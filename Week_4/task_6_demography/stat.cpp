//
// Created by GAlekseyV on 18.09.2018.
//

#include "stat.h"
#include <algorithm>
#include <iostream>

void PrintStats(vector<Person> persons){
    // Compute median age
        cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons))
    << endl;

    // Females
    auto it = partition(begin(persons), end(persons),
            [](Person p){
        return p.gender == Gender::FEMALE;
    });
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), it)<< endl;

    // Males
    it = partition(begin(persons), end(persons),
                        [](Person p){
                            return p.gender == Gender::MALE;
                        });
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), it)<< endl;

    // Employed females
    it = partition(begin(persons), end(persons),
                        [](Person p){
                            return p.gender == Gender::FEMALE && p.is_employed;
                        });
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it)
    << endl;

    // Unemployed females
    it = partition(begin(persons), end(persons),
                   [](Person p){
                       return p.gender == Gender::FEMALE && !p.is_employed;
                   });
    cout << "Median age for unemployed females = "
    << ComputeMedianAge(begin(persons), it) << endl;

    // Employed males
    it = partition(begin(persons), end(persons),
                   [](Person p){
                       return p.gender == Gender::MALE && p.is_employed;
                   });
    cout << "Median age for employed males = "
        << ComputeMedianAge(begin(persons), it) << endl;
    // Unemployed males
    it = partition(begin(persons), end(persons),
                   [](Person p){
                       return p.gender == Gender::MALE && !p.is_employed;
                   });
    cout << "Median age for unemployed males = "
        << ComputeMedianAge(begin(persons), it) << endl;
}