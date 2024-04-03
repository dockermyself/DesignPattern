//
// Created by feng on 2020/11/16.
//

#include "Decorator.h"
#include <iostream>
using namespace std;
std::string Mocha::getDescription() const {
    return _beverage->getDescription() + ",Mocha";
}

double Mocha::cost() {
    return 0.5 + _beverage->cost();
}

std::string Soy::getDescription() const {
    return  _beverage->getDescription() + ",Soy";
}

double Soy::cost() {
    return 0.2 + _beverage->cost();
}


void testDrecrator(){
    Decaf decaf;
    Espresso espresso;
    Mocha mocha(&decaf);
    Soy soy(&mocha);


    cout <<  soy.cost() <<  endl;
    cout << "[" << soy.getDescription() << "]" << endl;
}