//
// Created by GAlekseyV on 18.09.2018.
//

#ifndef YELLOW_BELT_RESPONCES_H
#define YELLOW_BELT_RESPONCES_H

#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct BusesForStopResponse {
    // Наполните полями эту структуру
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    // Наполните полями эту структуру
    string bus;
    vector<string> stops;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);


// Дополнительные функции
template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true;
    for (const auto& i : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << Join(v, ' ');
}

#endif //YELLOW_BELT_RESPONCES_H
