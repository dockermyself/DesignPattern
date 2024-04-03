//
// Created by feng on 2020/11/12.
//

#ifndef DESIGNPATTERN_FACTORY_H
#define DESIGNPATTERN_FACTORY_H
#include <string>
#include <iostream>
#include <deque>
#include <mutex>

class Pizza{
    std::string name_;
public:
    explicit Pizza(std::string& name):name_(name){}
    virtual void prepare() = 0;
    void cut();
    void bake();
};


class GreekPizza:public Pizza{
public:
    explicit GreekPizza(std::string& name):Pizza(name){}
    void prepare() override;
};

class CheesePizza:public Pizza{
public:
    explicit CheesePizza(std::string& name):Pizza(name){}

    void prepare() override;

};
class PapperPizza:public Pizza{
public:
    explicit PapperPizza(std::string& name):Pizza(name){}

    void prepare() override;
};




class SimpleFactory{
protected:
    static Pizza* creatPizza(std::string& name);
};
class Store:public SimpleFactory{
    std::deque<std::string> queue_;
    std::mutex lock_;
public:
    void orderPizza();
    void makePizza();
};


#endif //DESIGNPATTERN_FACTORY_H
