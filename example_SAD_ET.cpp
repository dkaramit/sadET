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

    Variable<LD> x(0.25,0);
    Variable<LD> y(3.2125,1);
    Constant<LD> z(-1);
    Constant<LD> c(1);

    cout<<exp(-x*(y+z))+log(x)*sin(y)<<endl;
    for(unInt i=0; i<2; ++i){
        for(unInt j=0; j<2; ++j){
            cout<<derivative(derivative(exp(-x*(y+z))+log(x)*sin(y),i),j)<<endl;
        }
    }




 
    /*notice that it takes a lot of time to comiple the following, but is evaluated instantly!*/
    // cout<<
    // exp(-(x+z)*c).derivative(1).derivative(1).derivative(1).derivative(1)
    // <<endl;

    
    return 0;
}