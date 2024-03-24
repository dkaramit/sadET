#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
using sadET::evaluate;
using sadET::derivative;

int main(){
    sadET::Constant<long double,0.4> c;
    sadET::Variable<0,double> x;
    sadET::Variable<1,double> y;

    std::map<sadET::IDType,long double> at= {{x.getID(),0.2},{y.getID(),0.8}} ;


    cout<<evaluate( derivative( sin(x) * cos(y) + pow( x, sin(y+c) ) ,  x,y ) , at )<<"\n";

    return 0;
}