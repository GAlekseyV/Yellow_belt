//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Напишите шаблонную функцию RemoveDuplicates, принимающую по ссылке вектор elements объектов типа T и
 * удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.
 * Гарантируется, что объекты типа T можно сравнивать с помощью операторов ==, !=, < и >.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements){
    sort(begin(elements), end(elements));
    auto new_end_it = unique(begin(elements), end(elements));
    elements.erase(new_end_it, end(elements));
}

int main(){
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}