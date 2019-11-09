//
// Created by GAlekseyV on 18.09.2018.
//
#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    if(stops_to_buses.count(stop) > 0){
        return BusesForStopResponse{stops_to_buses.at(stop)};
    }
    return {};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    if(buses_to_stops.count(bus) > 0){
        return {bus, buses_to_stops.at(bus), stops_to_buses};
    }
    return {};
}

AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
    return AllBusesResponse{buses_to_stops};
}
