/*
 * Action.h
 *
 *  Created on: 13 сент. 2018 г.
 *      Author: aleled
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <memory>
#include <string>
#include <iosfwd>

namespace person {

class Person;
class Action;

std::ostream& operator<<(std::ostream& os, const Action& a);

class Action {
public:
    virtual std::ostream& Print(std::ostream& os) const = 0;
};

class WalkAction: public Action {
public:
    WalkAction(const std::string& destinationArg);
    virtual std::ostream& Print(std::ostream& os) const override;
private:
    const std::string& destination;
};

class LearnAction: public Action {
public:
    virtual std::ostream& Print(std::ostream& os) const override;
};

class TeachAction: public Action {
public:
    TeachAction(const std::string& subjectArg);
    virtual std::ostream& Print(std::ostream& os) const override;
private:
    const std::string& subject;
};

class CheckAction: public Action {
public:
    CheckAction(Person& p);
    virtual std::ostream& Print(std::ostream& os) const override;
private:
    Person& person;
};

class SingAction: public Action {
public:
    SingAction(const std::string& songArg);
    virtual std::ostream& Print(std::ostream& os) const override;
private:
    const std::string& song;

};

} /* namespace person */

#endif /* ACTION_H_ */
