//
// Created by GAlekseyV on 18.09.2018.
//

#ifndef YELLOW_BELT_STAT_H
#define YELLOW_BELT_STAT_H

#include "person.h"

#include <vector>

using namespace std;

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person& lhs, const Person& rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons);

#endif //YELLOW_BELT_STAT_H
