//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers, выполняющую поиск первого отрицательного
 * числа в нём и выводящую в стандартный вывод все числа, расположенные левее найденного, в обратном порядке.
 * Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке.
 */
//#include "../../test_framework/test_framework.h"
//#include "tests.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers){
    vector<int>::const_iterator it = find_if(begin(numbers), end(numbers),
            [](auto& num){return num < 0;});
    while(it != begin(numbers)){
        it--;
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    PrintVectorPart({6, 1, 8, -5, 4});
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    PrintVectorPart({6, 1, 8, 5, 4});
    return 0;
}