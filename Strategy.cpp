//
// Created by feng on 2020/11/23.
//

#include "Strategy.h"
#include <iostream>
using namespace std;

People::People(const std::string &name, size_t height, size_t age) : _name(name), _height(height), _age(age) {}

const std::string &People::getName() const {
    return _name;
}

size_t People::getHeight() const {
    return _height;
}

size_t People::getAge() const {
    return _age;
}

std::ostream &operator<<(std::ostream &os, const People &people) {
    os << "[" << "name: " << people._name << " height: " << people._height << " age: " << people._age << "]";
    return os;
}


void testStrategy(){
    People people[] = {People("jack",178,25),
                       People("rose",165,23),
                       People("xxx",170,30),
                       People("aaa",180,20),
                       People("bbb",170,28)};

    BubbleSort(people,NameComporator());
    for(People& p : people){
        cout << p << endl;
    }
}