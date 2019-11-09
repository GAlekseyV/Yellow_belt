//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Реализуйте сортировку слиянием, разбивая диапазон на 3 равные части, а не на 2.
 * Гарантируется, что длина исходного диапазона является степенью 3.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    // Если диапазон меньше 2 элементов, то выйти из функции
    if(range_end - range_begin > 1){
        // Создать вектор, содержащий все элементы текущего диапазона
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        // Разбить вектор на три равные части
        RandomIt end_part1_It = elements.begin() + elements.size() / 3;
        RandomIt end_part2_It = end_part1_It + elements.size() / 3;
        // Вызвать функцию рекурсивно от каждой трети вектора
        MergeSort(begin(elements), end_part1_It);
        MergeSort(end_part1_It, end_part2_It);
        MergeSort(end_part2_It, end(elements));
        // С помощью алгоритма merge слить отсортированные трети, записать полученный отсортированный диапазон в
        // вместо исходного
        vector<typename RandomIt::value_type> t;
        merge(begin(elements), end_part1_It, end_part1_It, end_part2_It, back_inserter(t));
        merge(begin(t), end(t), end_part2_It, end(elements), range_begin);
    }
    return;
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}