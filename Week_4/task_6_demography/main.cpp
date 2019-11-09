//
// Created by GAlekseyV on 18.09.2018.
//
#include "person.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintStats(vector<Person> persons);

int main() {
    vector<Person> persons = {
            {31, Gender::MALE, false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE, true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE, false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
