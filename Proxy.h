//
// Created by feng on 2020/11/17.
//

#ifndef DESIGNPATTERN_PROXY_H
#define DESIGNPATTERN_PROXY_H
#include <functional>

class Aspect{
public:
    virtual void request() = 0;
};


class Subject : public Aspect{
public:
    void request() override;
};

class Log : public Aspect{
    Aspect* _aspect = nullptr;
public:
    explicit Log(Aspect *aspect);

    void request() override;

private:
    void before();
    void after();
};

class Time : public Aspect{
    Aspect* _aspect = nullptr;
public:
    explicit Time(Aspect *aspect);

    void request() override;

private:
    void before();
    void after();
};






#endif //DESIGNPATTERN_PROXY_H
