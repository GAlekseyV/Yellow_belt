//
// Created by GAlekseyV on 17.09.2018.
//

#include "tests.h"
#include "../../test_framework/test_framework.h"

#include <vector>

using namespace std;

void TestSum(){
    AssertEqual(Sum(-10, 15), 5, "Simple test");
}

void TestReverse(){
    AssertEqual(Reverse("abcdefgh"), "hgfedcba", "Simpe string reverse test");
}

void TestSort(){
    vector<int> nums{5, 4, 3, 1, 0};
    vector<int> expected{0, 1, 3, 4, 5};
    Sort(nums);
    AssertEqual(nums, expected, "Sort vector test");
}