//
// Created by feng on 2020/11/23.
//

#ifndef DESIGNPATTERN_CHAINOFRESPONSIBILITY_H
#define DESIGNPATTERN_CHAINOFRESPONSIBILITY_H


#include <string>
#include <vector>
class Filter{
protected:
    Filter* _filter = nullptr;
public:
    explicit Filter(Filter *filter) : _filter(filter) {}
    virtual bool doFilter(std::string& msg) = 0;
    void setNextFilter(Filter* filter){
        _filter = filter;
    }
};


class A_Filter:public Filter{
public:
    explicit A_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'a' || msg.at(i) == 'A'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'a' ? "_a" : "_A");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};

class B_Filter:public Filter{
public:
    explicit B_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'b' || msg.at(i) == 'B'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'b' ? "_b" : "_B");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};


class C_Filter:public Filter{
public:
    explicit C_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'c' || msg.at(i) == 'C'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'c' ? "_c" : "_C");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};

class X_Filter:public Filter{
public:
    explicit X_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'x' || msg.at(i) == 'X'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'x' ? "_x" : "_X");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};
class Y_Filter:public Filter{
public:
    explicit Y_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'y' || msg.at(i) == 'Y'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'y' ? "_y" : "_Y");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};
class Z_Filter:public Filter{
public:
    explicit Z_Filter(Filter *filter = nullptr) : Filter(filter) {}

    bool doFilter(std::string& msg) override {
        std::vector<std::size_t> v_pos;
        for(std::size_t i = 0;i < msg.length();++i){
            if(msg.at(i) == 'z' || msg.at(i) == 'Z'){
                v_pos.push_back(i);
            }
        }
        std::string str;
        std::size_t start = 0;
        for(std::size_t pos : v_pos){
            str += msg.substr(start,pos-start) + (msg.at(pos) == 'z' ? "_z" : "_Z");
            start = pos+1;
        }
        str += msg.substr(start);
        msg = str;
        return _filter != nullptr && _filter->doFilter(msg);
    }
};

class ChainFilter : public Filter{
    std::vector<Filter*> _chain;
public:
    explicit ChainFilter(Filter *filter = nullptr) : Filter(filter) {}

    void add(Filter* filter){
        _chain.push_back(filter);
    }

    bool doFilter(std::string &msg) override {
        for(auto f : _chain){
            f->doFilter(msg);
        }
        return _filter != nullptr && _filter->doFilter(msg);
    }

};
void testChainOfResponsibility();
#endif //DESIGNPATTERN_CHAINOFRESPONSIBILITY_H
