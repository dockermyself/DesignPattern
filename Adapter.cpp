//
// Created by feng on 2020/11/13.
//

#include "Adapter.h"
#include <iostream>
using namespace std;
void AdapterCompare::compare(const std::initializer_list<int> &ini_list) {
    bool f = false;
    int _max = 0;
    for(auto& x : ini_list){
        if(!f){
            _compare.compare(x,x);
            _max = _compare.getCompareValue();
            f = true;
            continue;
        }
        _compare.compare(x,_max);
        _max = _compare.getCompareValue();
    }

}

void testAdapter(){
    AdapterCompare cmp;
    cmp.compare({20,19,18,1,2,3,4,5,6,7,8,9});
    std::cout << cmp.getCompareValue() << std::endl;
}