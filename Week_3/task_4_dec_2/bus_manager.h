//
// Created by GAlekseyV on 18.09.2018.
//

#ifndef YELLOW_BELT_BUS_MANAGER_H
#define YELLOW_BELT_BUS_MANAGER_H

#include "responses.h"

#include <map>
#include <string>
#include <vector>

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

#endif //YELLOW_BELT_BUS_MANAGER_H
