//
// Created by feng on 2020/11/13.
//

#include "Builder.h"
#include <iostream>
using namespace std;



CarBuild* Porsche::buildWheel() {
    Wheel* wheel = _car->getWheel();
    wheel->setDiameter(200);
    wheel->setNum(4);
    cout << "building wheel has " << wheel->getNum() << \
            " wheels, every wheel's diameter is " << wheel->getDiameter() << endl;
    return this;

}

CarBuild* Porsche::buildPlate() {
    Plate* plate = _car->getPlate();
    plate->setHeavy(10000);
    plate->setHeight(2.5);
    plate->setWidth(10);
    cout << "building plate' heavy is "<< plate->getHeavy() << ", its height is " \
         << plate->getHeight() << ", its width is " << plate->getWidth() << endl;
    return this;

}

CarBuild* Porsche::buildBody() {
    Body *body = _car->getBody();
    body->setColor("black");
    cout << "building body's color is " << body->getColor() << endl;
    return this;
}


int Wheel::getNum() const {
    return _num;
}

int Wheel::getDiameter() const {
    return _diameter;
}

void Wheel::setNum(int num) {
    _num = num;
}

void Wheel::setDiameter(int diameter) {
    _diameter = diameter;
}

void Plate::setHeavy(double heavy) {
    _heavy = heavy;
}

void Plate::setWidth(double width) {
    _width = width;
}

void Plate::setHeight(double height) {
    _height = height;
}

double Plate::getHeavy() const {
    return _heavy;
}

double Plate::getWidth() const {
    return _width;
}

double Plate::getHeight() const {
    return _height;
}

void Body::setColor(const string &color) {
    _color = color;
}

const string &Body::getColor() const {
    return _color;
}


CarDirector::CarDirector(CarBuild *carBuild) : _carBuild(carBuild) {}

void CarDirector::setCarBuild(CarBuild *carBuild) {
    _carBuild = carBuild;
}

CarBuild* Benz::buildWheel() {
    Wheel* wheel = _car->getWheel();
    wheel->setDiameter(250);
    wheel->setNum(4);
    cout << "building wheel has " << wheel->getNum() << \
            " wheels, every wheel's diameter is " << wheel->getDiameter() << endl;
    return this;
}

CarBuild* Benz::buildPlate() {
    Plate* plate = _car->getPlate();
    plate->setHeavy(15000);
    plate->setHeight(3);
    plate->setWidth(15);
    cout << "building plate' heavy is "<< plate->getHeavy() << ", its height is " \
         << plate->getHeight() << ", its width is " << plate->getWidth() << endl;
    return this;
}

CarBuild* Benz::buildBody() {
    Body *body = _car->getBody();
    body->setColor("blue");
    cout << "building body's color is " << body->getColor() << endl;
    return this;
}

Benz::~Benz() = default;

void testBuild(){
    Porsche porsche;
    Benz benz;
    CarDirector car(&porsche);
    car.makeCar();
    car.setCarBuild(&benz);
    car.makeCar();
}