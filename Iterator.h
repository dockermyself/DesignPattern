//
// Created by feng on 2020/11/20.
//

#ifndef DESIGNPATTERN_ITERATOR_H
#define DESIGNPATTERN_ITERATOR_H
#include <iostream>
#include <memory.h>
template <typename E>
class Collection{
public:
    virtual void add(const E& element) = 0;
    virtual int size() = 0;
    virtual E& operator[](std::size_t x) = 0;
};
template <typename E>
class Iteratorable{
public:
    virtual bool hasNext() = 0;
    virtual E& next() = 0;
};

template <typename E>
class ArrayList:public Collection<E>{
    class Iterator : public Iteratorable<E>{
        std::size_t _index = 0;
        Collection<E>& _c;
    public:
        using Iter =  ArrayList::Iterator;
        Iterator(size_t index, Collection<E> &c) : _index(index), _c(c) {}
        bool hasNext() override {
            return _index < _c.size();
        }

        E &next() override {
            return _c[_index++];
        }
    };
public:
    std::size_t _capacity = 1;
    ArrayList():_data(new E[_capacity]),_len(0){}
    void add(const E &element) override {
        if(_len >= _capacity){
            E* data = new E[_capacity*2];
            memcpy(data,_data, _capacity*sizeof(E));
            delete _data;
            _data = data;
            _capacity = _capacity*2;
        }
        _data[_len] = element;
        ++_len;
    }
    int size() override {
        return _len;
    }
    E& operator[] (std::size_t x) override {
        return _data[x];
    }
    Iterator GetIterator(){
        return Iterator(0,*this);
    }
private:
    E* _data = nullptr;
    size_t _len = 0;



};


#endif //DESIGNPATTERN_ITERATOR_H
