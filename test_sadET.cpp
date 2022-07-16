#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
using sadET::evaluate;
using sadET::derivative;

int main(){
    sadET::Variable<0,long double> x;
    sadET::Variable<1,double> y;

    auto z=(x+x)*y;
    
    std::map<sadET::IDType,double> at;
    at[0]=10;
    at[1]=1.23;

    cout<<z.evaluate(at)<<"\n";
    cout<<evaluate(10.,at)<<"\n";

    cout<<evaluate(derivative(z,x),at)<<"\n";
    cout<<evaluate(derivative(z,y),at)<<"\n";
    cout<<evaluate(derivative(10.,x), at)<<"\n";

    
    return 0;
}