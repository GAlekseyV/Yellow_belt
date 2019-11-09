//
// Created by GAlekseyV on 20.09.2018.
//
/*
 * Напишите функцию FindStartsWith:
 * принимающую отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
 * возвращающую диапазон строк, начинающихся с символа prefix, в виде пары итераторов.
 * Если итоговый диапазон пуст, его границы должны указывать на то место в контейнере,
 * куда можно без нарушения порядка сортировки вставить любую строку, начинающуюся с символа prefix
 * (подобно алгоритму equal_range). Гарантируется, что строки состоят лишь из строчных латинских букв
 * и символ prefix также является строчной латинской буквой.
 * Поиск должен осуществляться за логарифмическую сложность — например, с помощью двоичного поиска
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
    // Диапазон пуст
    while (range_begin != range_end){
        bool a = ((*range_begin).compare(0, prefix.size(), prefix) == 0);
        bool b = ((*prev(range_end)).compare(0, prefix.size(), prefix) == 0);
        if(((*range_begin).compare(0, prefix.size(), prefix) == 0)
        && ((*prev(range_end)).compare(0, prefix.size(), prefix) == 0)){
            return {range_begin, range_end};
        }
        auto it = range_begin + (range_end - range_begin)/2;
        if((*it).compare(0, prefix.size(), prefix) == 0){
            auto range_it1 = FindStartsWith(range_begin, it, prefix);
            auto range_it2 = FindStartsWith(it, range_end, prefix);
            return {range_it1.first, range_it2.second};
        }else if((*it).compare(0, prefix.size(), prefix) > 0){
            range_end = it;
        }else{
            range_begin = next(it);
        }
    }
    return {range_begin, range_end};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}


/* Решение авторов курса

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
  RandomIt range_begin, RandomIt range_end, string prefix) {

  // Все строки, начинающиеся с prefix, больше или равны строке "<prefix>"
  auto left = lower_bound(range_begin, range_end, prefix);

  // Составим строку, которая в рамках буквенных строк является
  // точной верхней гранью множества строк, начинающихся с prefix
  string upper_bound = prefix;
  ++upper_bound[upper_bound.size() - 1];

  // Первое встреченное слово, не меньшее upper_bound,
  // обязательно является концом полуинтервала
  auto right = lower_bound(range_begin, range_end, upper_bound);

  return {left, right};
}
*/