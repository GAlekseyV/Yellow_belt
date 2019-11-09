//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Напишите шаблонную функцию FindGreaterElements, принимающую множество elements объектов типа T и ещё один объект
 * border типа T и возвращающую вектор из всех элементов множества, бо́льших border, в возрастающем порядке.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    auto greater_it = find_if(begin(elements), end(elements), [border](const T& element){return border < element;});
    return vector<T>(greater_it, end(elements));
}

int main(){
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

    return 0;
}
