//
// Created by feng on 2020/11/19.
//

#include "ThreadCommand.h"
#include <iostream>

using namespace std;
void LightOff::execute() {
    if(_receive->getState()){
        _receive->set(false);
        _time.store(60);
        thread t([this]{
            while (_time > 0){
                --_time;
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            _receive->update();
        });
        _thread = std::move(t);
    }
}

void LightOff::undo() {
    if(_receive->getState() && _time > 0){
        if(_receive->set(true)){
            cout << "命令取消成功" << endl;
        }
        _thread.join();
    }

}

void Light::update() {
    unique_lock<mutex> g(lock);
    _state =  _buf;
}


void Light::show() {
    thread t([this]{
        while (true){
            if(_state)
            {
                cout << "light on......" << endl;
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }
    });
    t.detach();
}

bool Light::set(bool state) {
    bool expected = _buf.load();
    return _buf.compare_exchange_weak(expected,state);
}

bool Light::getState() {
    unique_lock<mutex> g(lock);
    return _state;
}

void LightOn::execute() {
    if(!_receive->getState()){
        _receive->set(true);
        _time.store(60);
        thread t([this]{
            while (_time > 0){
                --_time;
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            _receive->update();
        });
        _thread = std::move(t);
    }
}

void LightOn::undo() {
    if(!_receive->getState() && _time > 0){
        if(_receive->set(false)){
            cout << "命令取消成功" << endl;
        } else{
            cout << "命令取消失败" << endl;
        }
        _thread.join();
    } else{
        cout << "命令取消失败" << endl;
    }

}
 void testThreadCommand(){
     Light light(false);
     LightOff off(&light);
     LightOn on(&light);
     on.execute();
     this_thread::sleep_for(chrono::milliseconds(1000));
     on.undo();
     off.execute();
//     off.undo();
     while (true);
}