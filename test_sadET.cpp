#include<iostream>
#include<cmath>

#include<sadET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double

using std::cout;
using std::endl;

using namespace sadET;


int main(){

    Variable<LD> x(2,0),y(3.2125,1);
    Constant<LD> c(0.1);

    return 0;
}