//
// Created by feng on 2020/11/13.
//

#include "Prototype.h"

std::ostream &operator<<(std::ostream &s, Sheep &sheep){
    s << "Sheep name is: " << sheep.name << "\nSheep age is: " << sheep.age;
    return s;
}
