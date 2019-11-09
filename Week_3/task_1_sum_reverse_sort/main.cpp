//
// Created by GAlekseyV on 17.09.2018.
//
#include "sum_reverse_sort.h"
#include "tests.h"
#include "../../test_framework/test_framework.h"

using namespace std;

int main(){
    TestRunner r;
    r.RunTest(TestSum, "TestSum");
    r.RunTest(TestReverse, "TestReverse");
    r.RunTest(TestSort, "TestSort");
    return 0;
}
