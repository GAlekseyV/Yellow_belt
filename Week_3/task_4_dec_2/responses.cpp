//
// Created by GAlekseyV on 18.09.2018.
//

#include "responses.h"

#include <iostream>

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    if(!r.buses.empty()){
        os << r.buses;
    }else{
        os << "No stop";
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    if(r.stops.empty()){
        os << "No bus";
    }else{
        for (const string& stop : r.stops) {
            os << "Stop " << stop << ": ";
            if(r.stops_to_buses.count(stop) > 0){
                if (r.stops_to_buses.at(stop).size() == 1) {
                    os << "no interchange";
                } else {
                    for (const string& other_bus : r.stops_to_buses.at(stop)) {
                        if (r.bus != other_bus) {
                            os << other_bus << " ";
                        }
                    }
                }
            }
            os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    if (r.buses_to_stops.empty()) {
        os << "No buses" << endl;
    } else {
        for (const auto& bus_item : r.buses_to_stops) {
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}