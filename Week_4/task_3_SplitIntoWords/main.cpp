//
// Created by GAlekseyV on 18.09.2018.
//
/*
 * Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.
 * Гарантируется, что:
 * строка непуста;
 * строка состоит лишь из латинских букв и пробелов;
 * первый и последний символы строки не являются пробелами;
 * строка не содержит двух пробелов подряд.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> words;
    auto start_word_it = begin(s);
    auto end_word_it = find(begin(s), end(s), ' ');
    while(end_word_it != end(s)){
        words.emplace_back(string(start_word_it, end_word_it));
        start_word_it = end_word_it + 1;
        end_word_it = find(start_word_it, end(s), ' ');
    }
    words.emplace_back(string(start_word_it, end(s)));
    return words;
}

int main(){
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
