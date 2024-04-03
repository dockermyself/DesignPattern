//
// Created by feng on 2020/11/16.
//

#ifndef DESIGNPATTERN_DECORATOR_H
#define DESIGNPATTERN_DECORATOR_H
#include <string>

class Beverage{
    std::string _des;
public:
    Beverage() = default;
    explicit Beverage(const std::string &des) : _des(des) {}

    virtual std::string getDescription() const { return _des;}

    virtual double cost() = 0;
};
//浓缩咖啡
class Espresso:public Beverage{
public:
    Espresso():Beverage("Espresso"){}

    double cost() override {
        return 2.0;
    }
};

//低咖啡因咖啡
class Decaf : public Beverage{
public:
    Decaf():Beverage("Decaf"){}

    double cost() override {
        return 4.0;
    }
};


class Mocha:public Beverage{
    Beverage* _beverage = nullptr;//装饰者含有被装饰的对象
public:
    explicit Mocha(Beverage *beverage) :_beverage(beverage){}

    std::string getDescription() const override;
    double cost() override;
};

class Soy:public Beverage{
    Beverage* _beverage = nullptr;
public:
    explicit Soy(Beverage *beverage): _beverage(beverage) {}

    double cost() override;

    std::string getDescription() const override;
};

void testDrecrator();
#endif //DESIGNPATTERN_DECORATOR_H
