//
// Created by feng on 2020/11/17.
//

#include "Proxy.h"
#include <iostream>
using namespace std;


void Subject::request() {
    cout << "do request" << endl;
}

Log::Log(Aspect *aspect) : _aspect(aspect) {}

void Log::before() {
    cout << "do Log before" << endl;
}

void Log::after() {
    cout << "do Log after" << endl;
}

void Log::request() {
    before();
    _aspect->request();
    after();
}

Time::Time(Aspect *aspect):_aspect(aspect) {}

void Time::before() {
    cout << "do Time before" << endl;
}

void Time::after() {
    cout << "do Time after" << endl;
}

void Time::request() {
    before();
    _aspect->request();
    after();
}
