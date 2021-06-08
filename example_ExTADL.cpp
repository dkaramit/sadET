#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;


#include<ExTADL.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double


int main(){

    Variable<LD> x(11);
    Constant<LD> c(5);

    
    // cout<<(x+x).evaluate()<<endl;
    // cout<<(x+c).evaluate()<<endl;
    // cout<<(x*x).evaluate()<<endl;
    // cout<<((c+x*x)+c*x).evaluate()<<endl;

    cout<<(x.derivative()+x.derivative()).evaluate()<<endl;
    cout<<(x.derivative()+c.derivative()).evaluate()<<endl;


    return 0;
}