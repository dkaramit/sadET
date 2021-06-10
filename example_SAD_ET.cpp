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

    sadET::Variable<LD> x(0.25,0);
    sadET::Variable<LD> y(3.2125,1);
    sadET::Constant<LD> z(-1);
    sadET::Constant<LD> c(1);

    cout<<sadET::exp(-x*(y+z))+sadET::log(x)*sadET::sin(y)<<endl;
    for(sadET::unInt i=0; i<2; ++i){
        for(sadET::unInt j=0; j<2; ++j){
            cout<<sadET::derivative(sadET::derivative(sadET::exp(-x*(y+z))+sadET::log(x)*sadET::sin(y),i),j)<<endl;
        }
    }

 
    /*notice that it takes a lot of time to comiple the following, but is evaluated instantly!*/
    // cout<<
    // exp(-(x+z)*c).derivative(1).derivative(1).derivative(1).derivative(1)
    // <<endl;

    
    return 0;
}