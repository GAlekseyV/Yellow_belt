//
// Created by GAlekseyV on 19.09.2018.
//
/*
 * Напишите функцию FindNearestElement, для множества целых чисел numbers и данного числа border возвращающую итератор
 * на элемент множества, ближайший к border. Если ближайших элементов несколько, верните итератор на наименьший из них.
 */
#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
    auto range_It = numbers.equal_range(border);
    if(range_It.first == range_It.second){
        if(range_It.first == numbers.begin()){
            return numbers.begin();
        }else if(range_It.first == numbers.end()){
            return prev(numbers.end());
        }else{
            if(border - *prev(range_It.first) > *range_It.second - border){
                return range_It.first;
            }else{
                return prev(range_It.first);
            }
        }
    }else{
        return range_It.first;
    }
}

int main(){
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}