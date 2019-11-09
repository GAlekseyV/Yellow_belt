//
// Created by GAlekseyV on 21.09.2018.
//

#ifndef YELLOW_BELT_DATABASE_H
#define YELLOW_BELT_DATABASE_H
#include "date.h"

#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <set>
#include <string>
#include <utility>

using Entry = std::pair<Date, std::string>;

class Database {
public:
    void Add(const Date &date, const std::string &event);

    //bool DeleteEvent(const Date& date, const std::string& event);

    //int DeleteDate(const Date& date);

    //std::vector<std::string> Find(const Date& date) const;

    void Print(std::ostream &os) const;

    int RemoveIf(std::function<bool (const Date&, const std::string&)> predicate);

    std::vector<Entry> FindIf(std::function<bool (const Date&, const std::string&)> predicate) const;

    Entry Last(const Date& date) const;

private:
    std::map<Date, std::vector<std::string>> storage;
    std::map<Date, std::set<std::string>> set_storage;

};

std::ostream& operator<<(std::ostream& os, const Entry& e);

#endif //YELLOW_BELT_DATABASE_H
