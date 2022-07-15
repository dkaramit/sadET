#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;


int main(){
    sadET::Variable<0,double> x;
    sadET::Variable<1,double> y;
    sadET::Constant<double> c=3;

    auto z=(x+y+y+c);
    
    std::map<sadET::IDType,double> at;
    at[0]=10;
    at[1]=1.23;

    cout<<z.evaluate(at)<<"\n";
    cout<<z.derivative(0).evaluate(at)<<"\n";
    cout<<z.derivative(1).evaluate(at)<<"\n";

    
    return 0;
}