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
    sadET::Variable<2,double> z;

    auto f= (z*d*(x + x*x)*y*y + c)*(z*d*(x + x*x)*y*y + c)*(z*d*(x + x*x)*y*y + c)*
            (z*d*(x + x*x)*y*y + c)*(z*d*(y + x*y)*y*y + c)*(z*d*(x + x*x)*y*y + c)*
            (z*d*(x + x*x)*y*y + c)*(z*d*(x + z*x)*y*y + c)*(z*d*(x + z*x)*y*y + c)*
            (z*d*(x + x*x)*y*y + c)*(z*d*(x + x*x)*z*x + c)*(z*d*(x + x*z)*y*z + c);


    std::map<sadET::IDType,long double> at={{0,-0.3},{1,1.23},{2,1e-7}};

    
    cout<<evaluate(c,at)<<"\n";
    cout<<evaluate(derivative(d  ,x), at)<<"\n";
    
    cout<<evaluate(f,at)<<"\n";
    cout<<evaluate(derivative(f,x),at)<<"\n";
    cout<<evaluate(derivative(f,y),at)<<"\n";
    cout<<evaluate(derivative(f,x,x),at)<<"\n";
    cout<<evaluate(derivative(f,y,y),at)<<"\n";
    cout<<evaluate(derivative(f,x,y),at)<<"\n";


    cout<<evaluate(derivative(f,x,y,z),at)<<"\n";
    
    return 0;
}