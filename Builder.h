//
// Created by feng on 2020/11/13.
//

#ifndef DESIGNPATTERN_BUILDER_H
#define DESIGNPATTERN_BUILDER_H
#include <string>
class Wheel{
    int _num = 0;
    int _diameter = 0;
public:
    int getNum() const;
    int getDiameter() const;

    void setNum(int num);
    void setDiameter(int diameter);
};
class Plate{
    double _heavy = 0.0;
    double _width = 0.0;
    double _height = 0.0;
public:
    void setHeavy(double heavy);
    void setWidth(double width);
    void setHeight(double height);

    double getHeavy() const;
    double getWidth() const;
    double getHeight() const;

};
class Body{
    std::string _color;
public:
    void setColor(const std::string &color);

    const std::string &getColor() const;
};
class Car {
    Wheel* _wheel = nullptr;
    Plate* _plate = nullptr;
    Body* _body = nullptr;
public:
    Car():_wheel(new Wheel()),_plate(new Plate()),_body(new Body()){}

    Wheel *getWheel() const {
        return _wheel;
    }

    Plate *getPlate() const {
        return _plate;
    }

    Body *getBody() const {
        return _body;
    }

    ~Car(){
        delete _wheel;
        delete _plate;
        delete _body;
    }
};

class CarBuild{
protected:
    Car* _car = nullptr;
public:
    CarBuild(): _car(new Car()){}
    virtual CarBuild* buildWheel() = 0;
    virtual CarBuild* buildPlate() = 0;
    virtual CarBuild* buildBody() = 0;
    Car* getMakedCar() const { return _car; }

    virtual ~ CarBuild(){
        delete _car;
    }

};

class Porsche:public CarBuild{
public:
    CarBuild* buildWheel() override;

    CarBuild* buildPlate() override;

    CarBuild* buildBody() override;

    ~Porsche() override = default;
};
//变化的地方设计为抽象
class Benz:public CarBuild{
public:
    CarBuild* buildWheel() override;

    CarBuild* buildPlate() override;

    CarBuild* buildBody() override;

    ~Benz() override;
};
class CarDirector{
    CarBuild* _carBuild = nullptr;//多态
public:
    explicit CarDirector(CarBuild *carBuild);

    void setCarBuild(CarBuild *carBuild);

    void makeCar(){
        _carBuild->buildWheel()->buildPlate()->buildBody()->getMakedCar();
    }

};

void testBuild();

#endif //DESIGNPATTERN_BUILDER_H
