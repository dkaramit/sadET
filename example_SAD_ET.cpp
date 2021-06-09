#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;


#include<SAD_ET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double







int main(){

    Variable<LD> x(10);
    Constant<LD> c(1);
    Constant<LD> z(5);

    cout<<(x+x+x+x+c).derivative().evaluate()<<endl;
    cout<<(x+x+x+x+c).derivative().derivative().evaluate()<<endl;
    cout<<(x+x+x+x+c).derivative().derivative().derivative().derivative().derivative().evaluate()<<endl;


    cout<<(x*x).evaluate()<<endl;
    cout<<(x*(x+c)*x).evaluate()<<endl;
    cout<<(z*x).derivative().evaluate()<<endl;
    cout<<(z*x*x).derivative().derivative().evaluate()<<endl;


    cout<<(z*(x+c*x+z)*x).derivative().derivative().evaluate()<<endl;

    cout<<exp(x*x).evaluate()<<endl;
    cout<<exp(x*x).derivative().evaluate()<<endl;
    
   
    return 0;
}