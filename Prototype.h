//
// Created by feng on 2020/11/13.
//

#ifndef DESIGNPATTERN_PROTOTYPE_H
#define DESIGNPATTERN_PROTOTYPE_H
#include <string>
#include <utility>
#include <ostream>

class Sheep{
    int age = 0;
    std::string name;
public:
    Sheep(int age, std::string  name) : age(age), name(std::move(name)) {

    }

    Sheep& clone() const {
        //决定深拷贝还是浅拷贝
        auto* s = new Sheep(*this);
        return *s;
    }
    friend std::ostream& operator << (std::ostream& s,Sheep& sheep);
};
std::ostream& operator << (std::ostream& s,Sheep& sheep);

#endif //DESIGNPATTERN_PROTOTYPE_H
