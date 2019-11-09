/*
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
 * Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного
 * изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого
 * человека, поэтому года? в последовательных вызовах методов ChangeLastName и ChangeFirstName не
 * обязаны возрастать.
 * Гарантируется, что все имена и фамилии непусты.
 * Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя
 * и фамилию человека по состоянию на конец данного года.
 * Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
 * Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
 * верните "last_name with unknown first name".
 * Если к данному году случилось изменение имени, но не было ни одного изменения фамилии,
 * верните "first_name with unknown last name".
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    if(names.empty()){
        return {};
    }
    const auto it = names.lower_bound(year);
    if(it == names.begin() && it->first != year){
        return {};
    }
    if(it == names.end()){
        return prev(it)->second;
    }
    if(it->first == year) {
        return it->second;
    }
//    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
//    for (const auto& item : names) {
//        // если очередной год не больше данного, обновляем имя
//        if (item.first <= year) {
//            name = item.second;
//        } else {
//            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
//            break;
//        }
//    }
    return prev(it)->second;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}
