//
// Created by GAlekseyV on 17.09.2018.
//
#include "phone_number.h"

#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

PhoneNumber::PhoneNumber(const string &inter_number){
    if(!inter_number.empty()){
        if(inter_number.front() == '+'){
            size_t pos = inter_number.find("-");
            size_t p_pos = pos;
            // Поиск разделителя "-"
            if(pos != string::npos && pos - 1u > 0){
                country_code_ = inter_number.substr(1u, pos - 1);
                pos = inter_number.find("-", pos + 1);
                if(pos != string::npos && pos - p_pos - 1 > 0){
                    city_code_ = inter_number.substr(p_pos + 1, pos - p_pos - 1);
                    if(pos != inter_number.size() - 1){
                        local_number_ = inter_number.substr(pos + 1, inter_number.size() - pos);
                    }else{
                        throw invalid_argument(inter_number);
                    }
                }else{
                    throw invalid_argument(inter_number);
                }
            }else {
                throw invalid_argument(inter_number);
            }
        }else{
            throw invalid_argument(inter_number);
        }
    }else {
        throw invalid_argument(inter_number);
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return '+' + country_code_ + "-" + city_code_ + "-" + local_number_;
}