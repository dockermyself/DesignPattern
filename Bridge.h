//
// Created by feng on 2020/11/14.
//

#ifndef DESIGNPATTERN_BRIDGE_H
#define DESIGNPATTERN_BRIDGE_H
//1、桥接模式实现了抽象化与实现化的脱耦。他们两个互相独立，不会影响到对方。
//2、对于两个独立变化的维度，使用桥接模式再适合不过了。
//3、对于"具体的抽象类"所做的改变，是不会影响到客户。
#include <iostream>
namespace bridge{
    class Color{
    public:
        virtual std::string color() = 0;
    };

    class Shape{
    public:
        virtual double area() = 0;
    };

    class Black:public Color{
    public:
        std::string color() override {
            return "黑色";
        }
    };

    class Rect:public Shape{
        double _width = 0;
        double _height = 0;
    public:
        Rect(double width, double height);

        double area() override;
    };


    class Bridge {
        Shape* _shape = nullptr;
        Color* _color = nullptr;
    public:
        Bridge(Shape *shape, Color *color) : _shape(shape), _color(color) {}
        void show(){
            std::cout << "需要 " << _shape->area() << _color->color() + "颜料" << std::endl;
        }
    };
}


#endif //DESIGNPATTERN_BRIDGE_H
