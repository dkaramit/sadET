#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
// using sadET::evaluate;
// using sadET::derivative;

int main(){
    sadET::Variable<1,double> x;
    sadET::Variable<2,double> y;
    sadET::Variable<3,double> z;

    cout<<print_expr(z+y+x)<<"\n";


    return 0;
}