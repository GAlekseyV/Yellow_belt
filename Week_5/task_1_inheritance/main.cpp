//
// Created by GAlekseyV on 21.09.2018.
//
/*
 * Определите до конца тела классов, соблюдая следующие требования:
 * - Класс Dog должен являться наследником класса Animal.
 * - Конструктор класса Dog должен принимать параметр типа string и
 * инициализировать им поле Name в классе Animal.
 */
#include <iostream>

using namespace std;

class Animal{
public:
    Animal(const string& n = "Animal") : Name(n){};
    const string Name;
};

class Dog : public Animal{
public:
    Dog(const string& n):Animal(n){};
    void Bark(){
        cout << Name << " barks: woof!" << endl;
    }
};

//int main(){
//    Dog d("Dog");
//    d.Bark();
//    return 0;
//}