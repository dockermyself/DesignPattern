//
// Created by feng on 2020/11/23.
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H
#include <iostream>
#include <string>
class People{
    std::string _name;
    std::size_t _height;
    std::size_t _age;
public:
    People(const std::string &name, size_t height, size_t age);

    const std::string &getName() const;

    size_t getHeight() const;

    size_t getAge() const;

    friend std::ostream &operator<<(std::ostream &os, const People &people);
};



template <typename T>
class Comporator{
public:
    virtual int compare(const T& x,const T& y) = 0;
};


class AgeComporator : public Comporator<People>{
public:
    int compare(const People &x, const People &y) override {
        if(x.getAge() > y.getAge()) return 1;
        else if (x.getAge() < y.getAge()) return -1;
        else return 0;
    }
};
class HeightComporator : public Comporator<People>{
public:
    int compare(const People &x, const People &y) override {
        if(x.getHeight() > y.getHeight()) return 1;
        else if (x.getHeight() < y.getHeight()) return -1;
        else return 0;
    }
};
class NameComporator : public Comporator<People>{
public:
    int compare(const People &x, const People &y) override {
        if(x.getName() > y.getName()) return 1;
        else if (x.getName() < y.getName()) return -1;
        else return 0;
    }
};

template <typename T,int N>
void BubbleSort(T(&data)[N],Comporator<T>&& cmp){
    if(data == nullptr || N <= 1) return;
    for(int i=0;i<N-1;++i)
        for(int j=0;j<N-1-i;++j)
            if(cmp.compare(data[j],data[j+1]) > 0)
            {
                T tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
}


#endif //DESIGNPATTERN_STRATEGY_H
