//
// Created by feng on 2020/11/23.
//

#ifndef DESIGNPATTERN_OBSERVER_H
#define DESIGNPATTERN_OBSERVER_H
#include <string>
#include <iostream>
#include <vector>
class Child;
class Event;

class Observer {
public:
    virtual void actionOnEvent(Event& event) = 0;
};
class Event{
    const Child& resource;
    const std::string name;
public:
    Event(const Child& resource, const std::string &name) : resource(resource), name(name) {}

    const Child &getResource() const {
        return resource;
    }
    const std::string &getName() const {
        return name;
    }

};

class Child{

    int  _state = 0;
    std::vector<Observer*> _observers;
public:
    enum {
        sleep,
        cry,
        hungry
    };
    int getState() const{
        return _state;
    }
    void onWake(){
        _state = hungry;
        Event event(*this,std::string("hungry"));
        for(Observer* o : _observers){
            o->actionOnEvent(event);
        }

    }
    void addObserver(Observer* observer){
        _observers.push_back(observer);
    }
};


class Dad : public Observer{
public:
    void actionOnEvent(Event& event) override {
        if(event.getResource().getState() == event.getResource().hungry){
            std::cout << "baby is " << event.getName() << std::endl;
            feed();
        }
    }
    void feed(){
        std::cout << "Dad... do feed" << std::endl;
    }
};

class Mum : public Observer{
public:
    void actionOnEvent(Event &event) override {
        if(event.getResource().getState() == event.getResource().cry){
            std::cout << "baby is " << event.getName() << std::endl;
            hug();
        }
    }
    void hug(){
        std::cout << "Mum... do hug" << std::endl;
    }
};

class Dog : public Observer{
public:
    void actionOnEvent(Event &event) override {
        if(event.getResource().sleep == event.getResource().getState()){
            std::cout << "baby is " << event.getName() << std::endl;
            bark();
        }
    }
    void bark(){
        std::cout << "Dog... do bark" << std::endl;
    }
};

void testObserver();

#endif //DESIGNPATTERN_OBSERVER_H
