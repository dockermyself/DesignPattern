//
// Created by feng on 2020/11/14.
//

#include "Bridge.h"

bridge::Rect::Rect(double width, double height) : _width(width), _height(height) {}

double bridge::Rect::area() {
    return _width*_height;
}
