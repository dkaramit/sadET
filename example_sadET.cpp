#include<iostream>
#include<cmath>


#include<sadET.hpp>
#include"FFANN.hpp"
// this is how you can define functions 
// (you can make it a class with overloaded operator() for more functionality)

template<typename T1, typename T2>
inline auto f(const T1 &x,const T2 &y)  {

    return sadET::exp(-x*(y-1))+sadET::log(3*x*+3*x*pow(4,x))*sadET::sin(y*2);
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

 
    /*notice that it takes a lot of time to comiple the following, but is evaluated quicly!*/
    cout<<f(x,y).derivative(1).derivative(0).derivative(1).derivative(0)<<endl;


    /*You can see that the FFANN works!*/
    std::vector<sadET::Variable<LD>> inputs{x};
    
    unsigned id=ann::FFAANN<LD>::NumberOfInputs;

    std::vector<sadET::Variable<LD>> w{ sadET::Variable<LD>(1,++id), sadET::Variable<LD>(-1,++id)   };
    std::vector<sadET::Variable<LD>> b{ sadET::Variable<LD>(0,++id), sadET::Variable<LD>(4,++id)   };

    ann::FFAANN<LD> brain(w,b);
    cout<<brain(inputs)[0].derivative(0).derivative(2)<<endl;


    return 0;
}