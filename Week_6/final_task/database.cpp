//
// Created by GAlekseyV on 21.09.2018.
//

#include "database.h"

#include <algorithm>

void Database::Add(const Date &date, const std::string &event) {
    // std::map<Date, std::vector<std::string>> storage
    // TODO Что будет если ключа в словаре нет?
    auto range_begin = storage[date].begin();
    auto range_end = storage[date].end();
    // Вектор по ключу пуст или равное событе уже есть в векторе
    if(set_storage[date].count(event) == 0){
        storage[date].push_back(event);
        set_storage[date].insert(event);
    }
}

//bool Database::DeleteEvent(const Date& date, const std::string& event) {
//    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
//        storage[date].erase(event);
//        return true;
//    }
//    return false;
//}

//int Database::DeleteDate(const Date& date) {
//    if (storage.count(date) == 0) {
//        return 0;
//    } else {
//        const int event_count = storage[date].size();
//        storage.erase(date);
//        return event_count;
//    }
//}

//std::set<std::string> Database::Find(const Date& date) const {
//    if (storage.count(date) > 0) {
//        return storage.at(date);
//    } else {
//        return {};
//    }
//}

void Database::Print(std::ostream &os) const {
    for (const auto& item : storage) {
        for (const std::string& event : item.second) {
            os << item.first << " " << event << std::endl;
        }
    }
}

int Database::RemoveIf(std::function<bool (const Date&, const std::string&)> predicate){
    // TODO написать определение метода RemoveIF
    // Удалить из базы данных все события, удовлетворяющие условию predicate,
    // и вернуть количество удалённых записей. Если условие пусто, результатом
    // выполнения команды должна стать очистка всей базы данных.
    std::vector<Entry> entries;
    int count_del_notes = 0;
    std::map<Date, std::vector<std::string>> new_storage;
    std::map<Date, std::set<std::string>> new_set_storage;
    for(const auto& [key, value] : storage ){
        for(const auto& event : value){
            if(!predicate(key, event)){
                // Все, что не надо удалять
                new_storage[key].push_back(event);
                new_set_storage[key].insert(event);
            }else{
                count_del_notes++;
            }
        }
    }
    // Обновим базу
    storage = new_storage;
    set_storage = new_set_storage;
    return count_del_notes;
}

std::vector<Entry> Database::FindIf(std::function<bool (const Date&, const std::string&)> predicate)const{
    // Найте все пары (дата, событие), которые содержатся в storage и удовлетворяют условию predicate.
    std::vector<Entry> entries;
    for(const auto& [key, value] : storage ){
        for(const auto& event : value){
            if(predicate(key, event)){
                entries.emplace_back(std::make_pair(key, event));
            }
        }
    }
    return entries;
}

Entry Database::Last(const Date& date)const{
    auto last_entry_it = storage.lower_bound(date);
    // Найденый ключ равен дате
    if(last_entry_it->first == date){
        // TODO Не забыть проверить, что список событий на дату не пуст?
        return std::make_pair(last_entry_it->first, last_entry_it->second.back());
    }
    // Далее дата в ключе не равна заданной дате
    // Хотя бы одна дата меньше заданной
    if(last_entry_it != storage.begin()){
        last_entry_it = prev(last_entry_it);
        return std::make_pair(last_entry_it->first, last_entry_it->second.back());
    }
    // Все даты больше заданной
    throw std::invalid_argument("No entries");
}


// Перегрузка операторов
std::ostream& operator<<(std::ostream& os, const Entry& e){
    os << e.first << " " << e.second;
    return os;
}