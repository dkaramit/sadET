#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
// using sadET::evaluate;
// using sadET::derivative;

int main(){
    sadET::Constant<float,3.4> c;
    sadET::Constant<long double,-1.223> d;
    sadET::Variable<0,long double> x;
    sadET::Variable<1,double> y;

    auto z=d * (x+x*x) *y*y + c;

    std::map<sadET::IDType,long double> at;
    at[0]=-2;
    at[1]=1.23;

    
    cout<<evaluate(c,at)<<"\n";
    cout<<evaluate(derivative(d  ,x), at)<<"\n";
    
    cout<<evaluate(z,at)<<"\n";
    cout<<evaluate(derivative(z,x),at)<<"\n";
    cout<<evaluate(derivative(z,y),at)<<"\n";
    cout<<evaluate(derivative(derivative(z,x),x),at)<<"\n";
    cout<<evaluate(derivative(derivative(z,y),y),at)<<"\n";
    cout<<evaluate(derivative(derivative(z,x),y),at)<<"\n";

    return 0;
}