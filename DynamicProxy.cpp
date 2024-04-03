//
// Created by feng on 2020/11/18.
//

#include "DynamicProxy.h"
#include <iostream>
using namespace std;
void request(const string& name){
    cout << "do request:" << name << endl;
}
struct Interface{
    virtual void before() {};
    virtual void after() {};
};
struct DynamicLog : public Interface{
    void before() override {
        cout << "do Log before" << endl;
    }
//    void after() override{
//        cout << "do Log after" << endl;
//    }
};

struct DynamicTime : public Interface{
//    void before() override{
//        cout << "do Time before" << endl;
//    }
    void after() override{
        cout << "do Time after" << endl;
    }
};

struct DynamicLock : public Interface{
    void before() override{
        cout << "do Lock before" << endl;
    }
    void after() override{
        cout << "do Lock after" << endl;
    }
};


void testDynamicProxy(){
    auto f = std::bind(request,string("open file please"));
    DynamicLog log;
    DynamicTime time;
    DynamicLock lock;
    DynamicProxy proxy(f);
    proxy.invoke(lock,log,time);
}