#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
using sadET::evaluate;
using sadET::derivative;

int main(){
    sadET::Constant<long double,3.4> c;
    sadET::Variable<0,double> x;
    sadET::Variable<1,double> y;

    std::map<sadET::IDType,long double> at;
    at[x.getID()]=2;
    at[y.getID()]=0.2;

    auto f=sin(log(exp(x-c)/y-cos(x)));
    auto g=sin(exp(c-y)/x-cos(x));
    auto h=pow(x+c,sin(y));

    cout<<evaluate(f,at)<<"\t";
    cout<<evaluate(g,at)<<"\t";
    cout<<evaluate(h,at)<<"\n";

    cout<<evaluate(derivative(f,x,y),at)<<"\t";
    cout<<evaluate(derivative(g,x,y,y),at)<<"\t";
    cout<<evaluate(derivative(h,y,x,x,x,x),at)<<"\n";

    cout<<"\n\n";

    cout<<print_expr(f)<<"\n\n";
    cout<<print_expr(g)<<"\n\n";
    cout<<print_expr(h)<<"\n\n";


    return 0;
}