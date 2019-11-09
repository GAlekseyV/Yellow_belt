/*
 * Action.cpp
 *
 *  Created on: 13 сент. 2018 г.
 *      Author: aleled
 */

#include "Person.h"
#include "Action.h"
#include <iostream>

namespace person {

std::ostream& operator<<(std::ostream& os, const Action& a) {
    return a.Print(os);
}

WalkAction::WalkAction(const std::string& destinationArg) :
        destination { destinationArg } {
}

std::ostream& WalkAction::Print(std::ostream& os) const {
    return os << "walks to: " << destination;
}

std::ostream& LearnAction::Print(std::ostream& os) const {
    return os << "learns";
}

TeachAction::TeachAction(const std::string& subjectArg) :
        subject { subjectArg } {
}

std::ostream& TeachAction::Print(std::ostream& os) const {
    return os << "teaches: " << subject;
}

CheckAction::CheckAction(Person& personArg) :
        person { personArg } {
}

std::ostream& CheckAction::Print(std::ostream& os) const {
    return os << "checks " << person.GetProfession() << ". " << person.GetProfession() << " name is "
            << person.GetName();
}

SingAction::SingAction(const std::string& songArg) :
        song { songArg } {
}

std::ostream& SingAction::Print(std::ostream& os) const {
    return os << "sings a song:  " << song;
}

} /* namespace person */
