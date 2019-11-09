//
// Created by GAlekseyV on 21.09.2018.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    Person(const string& name, const string& profession = "Person")
    : Name(name), Profession(profession){}

    virtual void Walk(const string& destination) const{
        PrintProfessionAndName() << " walks to: " << destination << endl;
    }

    ostream& PrintProfessionAndName(ostream& os = cout) const {
        PrintProfession() << ": ";
        PrintName();
        return os;
    }

    ostream& PrintName(ostream& os = cout) const {
        os << Name;
        return os;
    }

    ostream& PrintProfession(ostream& os = cout) const {
        os << Profession;
        return os;
    }

protected:
    const string Name;
    const string Profession;
};

class Student: public  Person{
public:

    Student(const string& name, const string& favouriteSong)
    : Person(name, "Student"), FavouriteSong(favouriteSong){
    }

    void Learn() const {
        PrintProfessionAndName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        PrintProfessionAndName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person{
public:
    Teacher(const string& name, const string& subject)
    :Person(name, "Teacher"), Subject(subject){
    }

    void Teach() const {
        PrintProfessionAndName() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
    : Person(name, "Policeman"){
    }

    void Check(const Person& p) const {
        PrintProfessionAndName() << " checks ";
        p.PrintProfession() << ". ";
        p.PrintProfession() << "'s name is: ";
        p.PrintName() << endl;
    }
};


void VisitPlaces(Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
