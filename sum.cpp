/*This is a simple program to show how you cna sum recursively without run-time loops.*/

#include<iostream>
#include<cmath>

#include<sadET.hpp>


using std::cout;
using std::endl;
// using sadET::evaluate;
// using sadET::derivative;

template<const size_t N>
auto Sum(auto x){ if constexpr(N>1){return Sum<N-1>(x)+x;}else{return x;} }

int main(){
    sadET::Constant<long double,3.45> c;
    sadET::Variable<0,double> x;
    sadET::Variable<1,double> y;

    std::map<sadET::IDType,long double> at;
    at[0]=1.32;
    at[1]=2.99;

    cout<<evaluate( Sum<4>(x*Sum<300>(c*y)) ,at)<<endl;
    cout<<evaluate( derivative(Sum<40>(x*Sum<300>(c*y*x)),x,y),at)<<endl;


    return 0;
}