//
// Created by feng on 2020/11/23.
//

#include "Observer.h"
void testObserver(){
    Dad dad;
    Mum mum;
    Dog dog;
    Child child;
    child.addObserver(&dad);
    child.addObserver(&mum);
    child.addObserver(&dog);
    child.onWake();
}