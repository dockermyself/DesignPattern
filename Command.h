//
// Created by feng on 2020/11/24.
//

#ifndef DESIGNPATTERN_COMMAND_H
#define DESIGNPATTERN_COMMAND_H
#include <string>
#include <vector>
#include <iostream>
#include <deque>

class Content{
    std::string _data;
public:
    Content() = default;
    explicit Content(const std::string &data);
    explicit Content(const char* data);

    const std::string &getData() const;
    std::string& insert(const std::string& ins);
    std::string& del(std::size_t len);
};


class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Insert : public Command{
    Content& _origin;
    const Content _inserted;
    bool _state = false;
public:
    Insert(Content& origin, const Content &inserted);
    void execute() override;
    void undo() override;

};

class Copy : public Command{
    Content& _origin;
    bool _state = false;
public:
    explicit Copy(Content& origin);
    void execute() override;
    void undo() override;

};


class ChainRollback:public Command{
    std::vector<Command*> v_commands;
public:
    void undo() override{
        for(int ix = (int)v_commands.size() - 1;ix >= 0;--ix){
            v_commands[ix]->undo();
        }
    }

    void execute() override {
        for(int ix = 0;ix < v_commands.size();++ix){
            v_commands[ix]->execute();
        }
    }

    void add(Command* cmd){
        v_commands.push_back(cmd);
    }

};
void testCommand();

#endif //DESIGNPATTERN_COMMAND_H
