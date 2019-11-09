//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Дано целое положительное число N, не превышающее 9. Выведите все перестановки чисел от 1 до N в
 * обратном лексикографическом порядке (см. пример).
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void PrintVector(const vector<int>& v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    unsigned n;
    cin >> n;
    vector<int> v(n);
    iota(rbegin(v), rend(v), 1);
    PrintVector(v);
    while(prev_permutation(begin(v), end(v))){
        PrintVector(v);
    }
    return 0;
}