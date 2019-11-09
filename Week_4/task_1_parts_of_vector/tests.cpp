//
// Created by GAlekseyV on 18.09.2018.
//

#include "tests.h"
#include "../../test_framework/test_framework.h"
#include <vector>

void TestPrintVectorParts(){
    vector<int> input{6, 1, 8, -5, 4};
    vector<int> expected{8, 1, 6};
    AssertEqual(input, expected, "Test 1");

    input = vector<int>{{-6, 1, 8, -5, 4}};
    expected = vector<int> {};
    AssertEqual(input, expected, "Nothing print");

    input = vector<int>{6, 1, 8, 5, 4};
    expected = vector<int> {4, 5, 8, 1, 6};
    AssertEqual(input, expected, "Print all");
}