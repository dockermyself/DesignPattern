//
// Created by feng on 2020/11/25.
//

#ifndef DESIGNPATTERN_MEDIATOR_H
#define DESIGNPATTERN_MEDIATOR_H
#include <array>
class Mediator;

struct Message{
    std::string _message;
    int _state;
public:
    Message(const std::string &message, int state) : _message(message), _state(state) {}
};
class Colleague{
protected:
    Mediator& _mediator;
public:
    explicit Colleague(Mediator &mediator) : _mediator(mediator) {}
    virtual Mediator& getMessage() = 0;
    virtual void sendMessage(const Message& msg) = 0;
};

class Alam : public Colleague{
public:
    Alam(Mediator &mediator);
    void sendMessage(const Message &msg) override;
    Mediator &getMessage() override;
};

class CoffeeMachine : public Colleague{
public:
    CoffeeMachine(Mediator &mediator);

    Mediator &getMessage() override;

    void sendMessage(const Message &msg) override;
};

class Mediator {
    std::array<Colleague*,4> arr_colleague;
public:
    enum _Colleague{
        e_alam = 0,
        e_coffeeMachine = 1,
        e_curtain = 2,
        e_tv = 3
    };
    void registerColleague(Colleague* colleague,std::size_t ix);
    void processMessage(Colleague* colleague,const Message& msg);
};





#endif //DESIGNPATTERN_MEDIATOR_H
