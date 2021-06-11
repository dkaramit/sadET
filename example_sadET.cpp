#include<iostream>
#include<cmath>


#include<sadET.hpp>

// this is how you can define functions 
// (you can make it a class with overloaded operator() for more functionality)

template<typename T1, typename T2>
inline auto f(const T1 &x,const T2 &y)  {

    return sadET::exp(-x*(y-1));//+sadET::log(3*x*+3*x*pow(4,x))*sadET::sin(y*2);
}


#ifndef LONG
    #define LONG
#endif
#define LD LONG double


using std::cout;
using std::endl;





int main(){

    sadET::Variable<LD> x(0.25,0),y(3.2125,1);

    cout<< f(x,y) <<endl;
    for(unsigned int i=0; i<2; ++i){
        for(unsigned int j=0; j<2; ++j){
            cout<<sadET::derivative(sadET::derivative(f(x,y),i),j)<<endl;
        }
    }

    /*you can set the input and evaluate it using evaulate() or operator()()*/
    // f.setInput(0.25,3.2125);
    // cout<< f() <<endl;
 
    /*notice that it takes a lot of time to comiple the following, but is evaluated instantly!*/
    
    auto res=f(x,y).derivative(1).derivative(0).derivative(1).derivative(0).derivative(1).derivative(0).derivative(1);
    // auto res=(x).derivative(1).derivative(1).derivative(1).derivative(1).derivative(1).derivative(1);
    cout<<res<<endl;


    return 0;
}