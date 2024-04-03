//
// Created by feng on 2020/11/23.
//
#include "ChainOfResponsibility.h"
#include <iostream>
using namespace std;
void testChainOfResponsibility(){
    C_Filter fc;
    B_Filter fb(&fc);
    A_Filter fa(&fb);
    ChainFilter ch;
    ch.add(&fa);

    string msg = "abcABC";
    ch.doFilter(msg);
    cout << msg << endl;
}