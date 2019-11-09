//
// Created by GAlekseyV on 13.09.2018.
//
/*
 * Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, но и для контейнеров.
 * Функция должна возвращать копию исходного контейнера, модифицировав его следующим образом:
 * -для vector элементы нужно возвести в квадрат;
 * -для map в квадрат нужно возвести только значения, но не ключи;
 * -для pair в квадрат нужно возвести каждый элемент пары.
 */
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;
template <typename T> vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs);
template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& lhs,
        const pair<First, Second>& rhs);
template <typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& lhs,
        const map<Key, Value> rhs);
template <typename T> T Sqr(const T& t);

// Объявляю шаблонные функции
// Умножение векторов
template <typename T> vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs){
    vector<T> mul_v(lhs.size());
    for(size_t i = 0; i < lhs.size(); ++i){
        mul_v[i] = (lhs[i] * rhs[i]);
    }
    return mul_v;
}
// Умножение пар
template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs,
                              const pair<First, Second>& rhs){
    return make_pair(lhs.first * rhs.first, lhs.second * rhs.second);
}
// Умножение словаря
template <typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& lhs,
                                                                  const map<Key, Value> rhs){
    map<Key, Value> mul_m;
    for(const auto& item : lhs){
        mul_m[item.first] = item.second * item.second;
    }
    return mul_m;
}
// Возведение в квадрат
template <typename T> T Sqr(const T& t){
    return t * t;
}

int main(){
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}