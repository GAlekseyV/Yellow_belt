//
// Created by GAlekseyV on 18.09.2018.
//

#ifndef YELLOW_BELT_QUERY_H
#define YELLOW_BELT_QUERY_H

#include <string>
#include <vector>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

// Ввод структуры из потока
istream& operator >> (istream& is, Query& q);

#endif //YELLOW_BELT_QUERY_H
