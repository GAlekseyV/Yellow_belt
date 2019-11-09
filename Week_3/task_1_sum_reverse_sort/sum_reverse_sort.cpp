//
// Created by GAlekseyV on 17.09.2018.
//
#include "sum_reverse_sort.h"

#include <algorithm>

int Sum(int x, int y){
    return x + y;
}

string Reverse(string s){
    reverse(begin(s), end(s));
    return s;
}

void Sort(vector<int>& nums){
    sort(begin(nums), end(nums));
}
