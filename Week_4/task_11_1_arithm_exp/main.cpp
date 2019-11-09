//
// Created by GAlekseyV on 20.09.2018.
//
/*
 * Реализуйте построение арифметического выражения согласно следующей схеме:
 * - изначально есть выражение, состоящее из некоторого целого числа x;
 * - на каждом шаге к текущему выражению применяется некоторая операция:
 * прибавление числа, вычитание числа, умножение на число или деление на число;
 * - перед применением операции выражение всегда должно быть заключено в скобки.
 */
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    deque<string> expression;
    int n, operand;
    string operation;
    cin >> operand >> n;
    expression.push_back(to_string(operand));
    while(n > 0){
        expression.push_front("(");
        expression.emplace_back(")");
        cin >> operation >> operand;
        expression.push_back(" " + operation + " ");
        expression.push_back(to_string(operand));
        --n;
    }

    for(auto elem : expression){
        cout << elem;
    }

    return 0;
}