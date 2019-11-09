//
// Created by GAlekseyV on 18.09.2018.
//

#ifndef YELLOW_BELT_PERSON_H
#define YELLOW_BELT_PERSON_H

enum class Gender{
    FEMALE,
    MALE
};

struct Person{
    int age;    // возраст
    Gender gender;  // пол
    bool is_employed; // имеет работу?
};
#endif //YELLOW_BELT_PERSON_H
