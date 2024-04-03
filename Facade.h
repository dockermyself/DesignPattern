//
// Created by feng on 2020/11/16.
//

#ifndef DESIGNPATTERN_FACADE_H
#define DESIGNPATTERN_FACADE_H

namespace facade{
    class Shape{
    public:
        virtual void draw() = 0;
        virtual ~Shape();
    };

    class Circle : public Shape{
    public:
        void draw() override;
        ~Circle() override;
    };

    class Rect : public Shape{
    public:
        void draw() override;
        ~Rect() override;
    };


    class Facade {
        Shape* circle = nullptr;
        Shape* rect = nullptr;
    public:
        Facade():circle(new Circle()),rect(new Rect()) {}

        void drawCircle(){
            if(circle) circle->draw();
        }
        void drawRect(){
            if(rect) rect->draw();
        }

        ~Facade(){
            delete circle;
            delete rect;
        }
    };
}

void testFacede();
#endif //DESIGNPATTERN_FACADE_H
