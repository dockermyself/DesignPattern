//
// Created by feng on 2020/11/13.
//

#ifndef DESIGNPATTERN_ADAPTER_H
#define DESIGNPATTERN_ADAPTER_H
#include <cmath>
#include <initializer_list>
//类适配器需要继承Compare类，灵活的不如对象适配器

class Compare{
    int _max = 0;
public:
    void compare(const int x,const int y){
        _max = std::fmax(x,y);
    }
    int getCompareValue() const {
        return _max;
    }
};


class Interface {
    virtual void compare(const std::initializer_list<int>& ini_list) = 0;
};

class AdapterCompare:public Interface{
    Compare _compare;
public:
    AdapterCompare() = default;
    void compare(const std::initializer_list<int> &ini_list) override;
    int getCompareValue(){
        return _compare.getCompareValue();
    }
};

void testAdapter();

#endif //DESIGNPATTERN_ADAPTER_H
