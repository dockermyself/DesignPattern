//
// Created by feng on 2020/11/18.
//

#ifndef DESIGNPATTERN_DYNAMICPROXY_H
#define DESIGNPATTERN_DYNAMICPROXY_H
#include <iostream>
#include <functional>
class DynamicProxy{
    using Req = std::function<void(void)>;
    Req _req;
public:
    explicit DynamicProxy(Req&& req) : _req(std::move(req)) {}
    template <typename T,typename... Args> void invoke(T&& asp,Args&&... args){
        asp.before();
        invoke(args...);
        asp.after();
    }
private:
    void invoke() {
        _req();
    }
};


void testDynamicProxy();
#endif //DESIGNPATTERN_DYNAMICPROXY_H
