/*
 * Person.h
 *
 *  Created on: 13 сент. 2018 г.
 *      Author: aleled
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Action.h"
#include <iosfwd>

namespace person {

class Person;
std::ostream& operator<<(std::ostream& os, const Person& p);

class Person {
public:
    Person(const std::string& nameArg, const std::string& professionArg);
    virtual std::ostream& Print(std::ostream& os) const;
    virtual void Walk(const std::string& destination);
    std::string GetName() const;
    std::string GetProfession() const;

protected:
    void DoAction(const Action& action);
    const std::string name;
    const std::string profession;
};

class Student: public Person {
public:
    Student(const std::string& nameArg, const std::string& favouriteSongArg);
    void SingSong();
    void Learn();
    virtual void Walk(const std::string& destination) override;
private:
    std::string favouriteSong;
};

class Teacher: public Person {
public:
    Teacher(const std::string& nameArg, const std::string& subjectArg);
    void Teach();
private:
    std::string subject;
};

class Policeman: public Person {
public:
    Policeman(const std::string& nameArg);
    void Check(Person& person);
};

} /* namespace person */

#endif /* PERSON_H_ */
