//
// Created by GAlekseyV on 20.09.2018.
//
/*
 * Модифицируйте решение предыдущей части так, чтобы предыдущее выражение обрамлялось скобками лишь при необходимости,
 * то есть только в том случае, когда очередная операция имеет бо́льший приоритет, чем предыдущая.
 */
#include <iostream>
#include <deque>
#include <map>
#include <string>

using namespace std;

int main(){
    deque<string> expression;
    map<string, int> op_to_p{{"+", 0},{"-", 0}, {"*", 1}, {"/", 1}, {"first", 2} };

    int n, operand;
    string operation, last_operation = "first";
    cin >> operand >> n;
    expression.push_back(to_string(operand));
    while(n > 0){
        cin >> operation >> operand;
        if(op_to_p[operation] > op_to_p[last_operation]){
            expression.push_front("(");
            expression.emplace_back(")");
        }
        last_operation = operation;
        expression.push_back(" " + operation + " ");
        expression.push_back(to_string(operand));
        --n;
    }

    for(auto elem : expression){
        cout << elem;
    }

    return 0;
}