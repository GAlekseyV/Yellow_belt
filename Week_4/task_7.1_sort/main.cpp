//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Напишите шаблонную функцию MergeSort, принимающую два итератора шаблонного типа RandomIt и сортирующую
 * заданный ими диапазон с помощью сортировки слиянием. Гарантируется, что:
 * - итераторы типа RandomIt аналогичны по функциональности итераторам вектора и строки, то есть их можно сравнивать с
 * помощью операторов <, <=, > и >=, а также вычитать и складывать с числами;
 * - сортируемые объекты можно сравнивать с помощью оператора <.
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
        // Разбить вектор на две равные части
        RandomIt middle_It = elements.begin() + elements.size() / 2;
        // Вызвать функцию рекурсивно от каждой половины вектора
        MergeSort(begin(elements), middle_It);
        MergeSort(middle_It, end(elements));
        // С помощью алгоритма merge слить отсортированные половины, записать полученный отсортированный диапазон в
        // вместо исходного
        merge(begin(elements), middle_It, middle_It, end(elements), range_begin);
    }
    return;
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}