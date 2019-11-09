//
// Created by GAlekseyV on 17.09.2018.
//

#include "tests.h"
#include "../../test_framework/test_framework.h"
#include "phone_number.h"

#include <string>
#include <exception>

using namespace std;

void TestValid(){
    /*Примеры:
    * +7-495-111-22-33
    * +7-495-1112233
    * +323-22-460002
    * +1-2-coursera-cpp
    * 1-2-333 - некорректный номер - не начинается на '+'
    * +7-1233 - некорректный номер - есть только код страны и города
    * */
    PhoneNumber phone("+7-495-111-22-33");
    AssertEqual(phone.GetInternationalNumber(), "+7-495-111-22-33", "Valid number 1. Get full number");
    AssertEqual(phone.GetCountryCode(), "7", "Valid number 1. Get country code");
    AssertEqual(phone.GetCityCode(), "495", "Valid number 1. Get city code");
    AssertEqual(phone.GetLocalNumber(),"111-22-33", "Valid number 1. Get local number" );

    phone = PhoneNumber("+7-495-1112233");
    AssertEqual(phone.GetInternationalNumber(), "+7-495-1112233", "Valid number 2. Get full number");
    AssertEqual(phone.GetCountryCode(), "7", "Valid number 2. Get country code");
    AssertEqual(phone.GetCityCode(), "495", "Valid number 2. Get city code");
    AssertEqual(phone.GetLocalNumber(),"1112233", "Valid number 2. Get local number" );

    phone = PhoneNumber("+323-22-460002");
    AssertEqual(phone.GetInternationalNumber(), "+323-22-460002", "Valid number 3. Get full number");
    AssertEqual(phone.GetCountryCode(), "323", "Valid number 3. Get country code");
    AssertEqual(phone.GetCityCode(), "22", "Valid number 3. Get city code");
    AssertEqual(phone.GetLocalNumber(),"460002", "Valid number 3. Get local number" );

    phone = PhoneNumber("+1-2-coursera-cpp");
    AssertEqual(phone.GetInternationalNumber(), "+1-2-coursera-cpp", "Valid number 4. Get full number");
    AssertEqual(phone.GetCountryCode(), "1", "Valid number 4. Get country code");
    AssertEqual(phone.GetCityCode(), "2", "Valid number 4. Get city code");
    AssertEqual(phone.GetLocalNumber(),"coursera-cpp", "Valid number 4. Get local number" );
}

void TestInvalid(){
    // 1-2-333 - некорректный номер - не начинается на '+'
    // +7-1233 - некорректный номер - есть только код страны и города
    try{
        PhoneNumber("1-2-333");
        throw runtime_error("1-2-333 is not valid number.");
    }catch (invalid_argument& e){

    }

    try{
        PhoneNumber("+7-1233");
        throw runtime_error("+7-1233 is not valid number.");
    }catch (invalid_argument& e){

    }

    try{
        PhoneNumber("+--");
        throw runtime_error("+-- is not valid number.");
    }catch (invalid_argument& e){

    }

    try{
        PhoneNumber("+8-5-");
        throw runtime_error("+8-5- is not valid number.");
    }catch (invalid_argument& e){

    }

    try{
        PhoneNumber("+888-555-");
        throw runtime_error("+8-555- is not valid number.");
    }catch (invalid_argument& e){

    }
}

void TestAll(){
    TestValid();
    TestInvalid();
}