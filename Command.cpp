//
// Created by feng on 2020/11/24.
//

#include "Command.h"
#include <iostream>
using namespace std;

Content::Content(const std::string &data) : _data(data) {}
Content::Content(const char *data): _data(string(data)) {}
const std::string &Content::getData() const {
    return _data;
}

std::string &Content::insert(const std::string &ins) {
    _data.insert(0,ins);
    return _data;
}

std::string &Content::del(std::size_t len) {
    _data = _data.substr(len);
    return _data;
}



void Insert::execute() {
    _origin.insert(_inserted.getData());
    _state = true;
}

void Insert::undo() {
    if(!_state)
        return;
    _origin.del(_inserted.getData().length());
    _state = false;
}

Insert::Insert(Content &origin, const Content &inserted) : _origin(origin), _inserted(inserted) {}


Copy::Copy(Content &origin) :_origin(origin){

}
void Copy::execute() {
    _origin.insert(_origin.getData());
    _state = true;
}

void Copy::undo() {
    if(!_state)
        return;
    _origin.del(_origin.getData().length()/2);
    _state = false;
}

void testCommand(){
    ChainRollback chain;
    Content c("hello,world");
    Insert in_1(c,Content("c++ program:"));
    Copy cp_1(c);
    Copy cp_2(c);
    Copy cp_3(c);
    Insert in_2(c,Content("c++ program:"));

    chain.add(&cp_1);
    chain.add(&in_1);
    chain.add(&cp_2);
    chain.add(&cp_3);
    chain.add(&in_2);




    chain.execute();
    chain.undo();
    cout << c.getData() << endl;
}




