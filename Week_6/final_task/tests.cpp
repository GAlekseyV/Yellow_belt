//
// Created by GAlekseyV on 22.09.2018.
//
#include "test_runner.h"
#include "date.h"

#include <vector>

using namespace std;

void TestParseDate(){
    {
        istringstream is("1-1-1");
        Date date = ParseDate(is);
        vector<int> parse{date.GetYear(), date.GetMonth(), date.GetDay()},
                    expected{1, 1, 1};
        AssertEqual(parse, expected, "Parse date 1");
    }

    {
        istringstream is("9999-12-31");
        Date date = ParseDate(is);
        vector<int> parse{date.GetYear(), date.GetMonth(), date.GetDay()},
                expected{9999, 12, 31};
        AssertEqual(parse, expected, "Parse date 2");
    }

    {
        istringstream is("2000-6-8");
        Date date = ParseDate(is);
        vector<int> parse{date.GetYear(), date.GetMonth(), date.GetDay()},
                expected{2000, 6, 8};
        AssertEqual(parse, expected, "Parse date 3");
    }


    {
        // Wrong format
        istringstream is("2000--6-8");
        string parse, expected = "Month value is invalid: -6";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse wrong date 1");
    }

    {
        // Wrong format
        istringstream is("2000-6 -8");
        string parse, expected = "Wrong date format: 2000-6";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse wrong date 2");
    }

    {
        // Wrong format
        istringstream is("2000-6-8-");
        string parse, expected = "Wrong date format: 2000-6-8-";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse wrong date 3");
    }

    // Invalid arguments
    {
        // Wrong month
        istringstream is("2000-13-8");
        string parse, expected = "Month value is invalid: 13";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse invalid month");
    }

    {
        // Wrong day
        istringstream is("2000-11-32");
        string parse, expected = "Day value is invalid: 32";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse invalid day");
    }

    {
        // Wrong month and day
        istringstream is("2000-20-34");
        string parse, expected = "Month value is invalid: 20";
        try{
            Date date = ParseDate(is);
        }catch (logic_error& er){
            parse = er.what();
        }
        AssertEqual(parse, expected, "Parse invalid month and day");
    }

}
