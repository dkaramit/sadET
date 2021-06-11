#include<iostream>
#include<cmath>

#include<sadET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double

using std::cout;
using std::endl;

int main(){

    sadET::Variable<LD> x(0.25,0),y(3.2125,1);
    sadET::Constant<LD> c(5);
    // cout<<x-x<<endl;
    // cout<<x-c<<endl;
    // cout<<c-x<<endl;
    // cout<<-c+x<<endl;
    // cout<<c-c<<endl;
    // cout<<33.2-x<<endl;
    // cout<<x-33.2<<endl;
    // cout<<2-x-33.2<<endl;
 
    // cout<<-1*c+x<<endl;
    // cout<<x-c<<endl;
    // cout<<c+x<<endl;
    // cout<<(1+x+2.3+c+x+x+c+c+c+x+x).derivative(0)<<endl;
    cout<<1*x*2.3*(-x+1+23+c)*x*x*c*c*c*x*x<<endl;

    return 0;
}