/*
 * Person.cpp
 *
 *  Created on: 13 сент. 2018 г.
 *      Author: aleled
 */

#include "Person.h"
#include <iostream>

namespace person {

std::ostream& operator<<(std::ostream& os, const Person& p) {
    return p.Print(os);
}

Person::Person(const std::string& nameArg, const std::string& professionArg) :
        name { nameArg }, profession { professionArg } {
}

std::ostream& Person::Print(std::ostream& os) const {
    return os << profession << ": " << name;
}

std::string Person::GetName() const {
    return name;
}

std::string Person::GetProfession() const {
    return profession;
}

void Person::DoAction(const Action& action) {
    std::cout << *this << " " << action << std::endl;
}

void Person::Walk(const std::string& destination) {
    WalkAction walk(destination);
    DoAction(walk);
}

Student::Student(const std::string& nameArg, const std::string& favouriteSongArg) :
        Person(nameArg, "Student"), favouriteSong { favouriteSongArg } {
}

void Student::Walk(const std::string& destination){
    Person::Walk(destination);
    SingSong();
}

void Student::SingSong() {
    SingAction sing(favouriteSong);
    DoAction(sing);
}

void Student::Learn() {
    LearnAction learn;
    DoAction(learn);
}

Teacher::Teacher(const std::string& nameArg, const std::string& subjectArg) :
        Person(nameArg, "Teacher"), subject { subjectArg } {
}

void Teacher::Teach() {
    TeachAction teach(subject);
    DoAction(teach);
}

Policeman::Policeman(const std::string& nameArg) :
        Person(nameArg, "Policeman") {
}

void Policeman::Check(Person& person) {
    CheckAction check(person);
    DoAction(check);
}

} /* namespace person */
