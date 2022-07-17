#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
// using sadET::evaluate;
// using sadET::derivative;

int main(){
    sadET::Constant<long double,3.4> c;
    sadET::Variable<0,double> x;
    sadET::Variable<1,double> y;

    std::map<sadET::IDType,long double> at;
    at[0]=2;

    // works
    cout<<print_expr(c+c)<<"\n";

    // works
    cout<<print_expr(c+x)<<"\n";

    // works
    cout<<print_expr(x+c)<<"\n";
    
    // works
    cout<<print_expr(c+x+c)<<"\n";
    cout<<print_expr(x+c+c)<<"\n";
    // works
    cout<<print_expr(x+c+x)<<"\n";

    // works
    cout<<print_expr(c+x+c+x)<<"\n";
    cout<<print_expr(x+c+x+c)<<"\n";
    cout<<print_expr(c+x+x+c)<<"\n";

    // works
    cout<<print_expr(y+x)<<"\n";

    // does not work
    cout<<print_expr(y+x+y+x)<<"\n";

    return 0;
}