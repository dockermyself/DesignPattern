//
// Created by feng on 2020/11/12.
//

#include "Factory.h"
#include <thread>
#include <chrono>
using namespace std;
void GreekPizza::prepare() {
    cout << "prepare GreekPizza" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}

void CheesePizza::prepare() {
    cout << "prepare CheesePizza" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}
void PapperPizza::prepare() {
    cout << "prepare PapperPizza" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}
void Store::orderPizza() {
    thread t([this]{
        string name;
        while (std::cin >> name){
            lock_guard<mutex> guard(lock_);
            queue_.push_front(name);
        }
    });
    t.detach();
}

void Store::makePizza() {
    while (true) {
        unique_lock<mutex> guard(lock_);
        if (queue_.empty()) {
            guard.unlock();
            this_thread::sleep_for(chrono::milliseconds(10));
            continue;
        }
        string name = queue_.back();
        queue_.pop_back();
        guard.unlock();
        Pizza *pizza = creatPizza(name);
        if (pizza) {
            pizza->prepare();
            pizza->cut();
            pizza->bake();
            cout << name << " pizza is finished" << endl;
        }
    }
}

void Pizza::bake() {
    std::cout << name_ << "do bake" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
}

void Pizza::cut() {
    std::cout << name_ << "do cut" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

Pizza *SimpleFactory::creatPizza(std::string &name) {
    Pizza *pizza = nullptr;
    if (name == "Cheese") {
        pizza = new CheesePizza(name);
    } else if (name == "Greek") {
        pizza = new GreekPizza(name);
    } else if (name == "Papper"){
        pizza = new PapperPizza(name);
    }
    else {
        cout << "this store can't make " + name + " pizza" << endl;
    }
    return pizza;
}


