//
// Created by GAlekseyV on 12.09.2018.
//
/*
 * Имеется база регионов, представленная вектором структур Region:
 * Здесь Lang — идентификатор языка:
 * Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и определяющую,
 * какое максимальное количество повторов она содержит. Две записи (объекты типа Region)
 * считаются различными, если они отличаются хотя бы одним полем.
 * Если все записи уникальны, считайте максимальное количество повторов равным 1.
 * Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для хранения ответа.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

//enum class Lang{
//    DE, FR, IT
//};
//
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

bool operator==(const Region& lhs, const Region& rhs){
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population)
        == tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

bool operator<(const Region& lhs, const Region& rhs){
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population)
           < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    int max_repeat_count = 0;
    if(!regions.empty()){
        map<Region, int> regions_to_cnt;
        for(auto& item : regions){
            regions_to_cnt[item] += 1;
        }
        for(auto& [region, cnt] : regions_to_cnt){
            if(cnt > max_repeat_count){
                max_repeat_count = cnt;
            }
        }
    }
    return max_repeat_count;
}

//int main() {
//    cout << FindMaxRepetitionCount({
//       {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Russia",
//               "Eurasia",
//               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//               89
//       }, {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Russia",
//               "Eurasia",
//               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//               89
//       },
//}) << endl;
//
//cout << FindMaxRepetitionCount({
//       {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Russia",
//               "Eurasia",
//               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//               89
//       }, {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Moscow",
//               "Toulouse",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               89
//       }, {
//               "Moscow",
//               "Russia",
//               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//               31
//       },
//}) << endl;
//
//    return 0;
//}