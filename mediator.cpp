//
// Created by feng on 2020/11/25.
//

#include "mediator.h"
#include <iostream>
using namespace std;



Mediator &Alam::getMessage() {
    return _mediator;
}

Alam::Alam(Mediator &mediator) : Colleague(mediator) {
    mediator.registerColleague(this,mediator.e_alam);
}
void Alam::sendMessage(const Message &msg) {
    _mediator.processMessage(this,msg);
}

void Mediator::registerColleague(Colleague *colleague, std::size_t ix) {
    arr_colleague[ix] = colleague;
}

void Mediator::processMessage(Colleague* colleague, const Message& msg) {
    cout << "do message:" << msg._message << endl;
}

CoffeeMachine::CoffeeMachine(Mediator &mediator) : Colleague(mediator) {
    mediator.registerColleague(this,mediator.e_coffeeMachine);
}

Mediator &CoffeeMachine::getMessage() {
    return _mediator;
}

void CoffeeMachine::sendMessage(const Message &msg) {
    _mediator.processMessage(this,msg);
}
