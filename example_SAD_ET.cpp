#include<iostream>
#include<cmath>


#include<SAD_ET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double


using std::cout;
using std::endl;

int main(){

    Variable<LD> x(0.1);
    Constant<LD> c(1);
    Constant<LD> z(-1);

    // cout<<(x+x)<<endl;
    // cout<<(x-x)<<endl;
    // cout<<-(c+x*x)<<endl;
    // cout<<exp(-(c+x*x)*z)+c<<endl;
    // cout<<derivative(exp(-(c+x*x)*z)+c)<<endl;
    // cout<<derivative(derivative(exp(-(x+z)*c)))<<endl;
    
    // cout<<exp(-(x+z)*c)/x- x*exp(x)<<endl;
    // cout<<derivative(derivative(exp(-(x+z)*c)/x - x*exp(x)))<<endl;
    // cout<<derivative(derivative(exp(-(x+z)*c)/x - x*exp(x)))*x<<endl;
   
    // cout<<log(x) *exp(x*z)<<endl;
    // cout<<derivative(derivative(log(x) *exp(x*z)))<<endl;


    // cout<<pow(x+c*exp(x),x+z)<<endl;
    // cout<<derivative(derivative(derivative(pow(x+c*exp(x),x+z))))<<endl;


    // cout<<cos(x)<<endl;
    // cout<<derivative(cos(x))+sin(x)<<endl;
    // cout<<sin(x)<<endl;
    // cout<<derivative(sin(x))-cos(x)<<endl;


    /*notice that it takes a lot of time to comiple the following, but is evaluated instantly!*/
    // cout<<
    // exp(-(x+z)*c).derivative().derivative().derivative().derivative()
    // <<endl;

    
    return 0;
}