//
// Created by feng on 2020/11/16.
//

#include "Facade.h"
#include <iostream>
using namespace std;
facade::Shape::~Shape() = default;
void facade::Circle::draw() {
    cout << "draw Circle" << endl;
}
facade::Circle::~Circle() = default;
void facade::Rect::draw() {
    cout << "draw Rect" << endl;

}
facade::Rect::~Rect() = default;

void testFacede(){
    facade::Facade f;
    f.drawCircle();
    f.drawRect();
}
