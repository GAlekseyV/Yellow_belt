//
// Created by GAlekseyV on 21.09.2018.
//

#include "date.h"

#include <string>

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if(new_month > 12 || new_month < 1){
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month = new_month;
    if(new_day > 31 || new_day < 1){
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day = new_day;
}


bool operator<(const Date& lhs, const Date& rhs){
    // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
    // создадим вектор из года, месяца и дня для каждой даты и сравним их
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

std::ostream& operator<<(std::ostream& stream, const Date& date){
    stream << std::setfill('0')
           << std::setw(4) << date.GetYear() <<
           '-' << std::setw(2) << date.GetMonth() <<
           '-' << std::setw(2) << date.GetDay();
    return stream;
}

bool operator!=(const Date& lhs, const Date& rhs){
    return std::vector<int> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}
        != std::vector<int> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs){
    return !(lhs != rhs);
}

Date ParseDate(std::istream &is) {
    // Формат даты: Год-Месяц-День.
    // Год - число от 0 до 9999;
    // Месяц - номер месяца от 1 до 12;
    // День - номер дня от 1 до 31;
    // После даты обязательно следует пробел.
    std::string date_string;
    is >> date_string;
    std::istringstream date_stream(date_string);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw std::logic_error("Wrong date format: " + date_string);
    }
    return Date(year, month, day);
}