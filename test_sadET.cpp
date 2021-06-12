#include<iostream>
#include<cmath>

#include<sadET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double

using std::cout;
using std::endl;

using namespace sadET;

#define CHECK(lh,op,rh) cout<<lh op rh<<endl; cout<<rh op lh<<endl;\
                        cout<<derivative(lh op rh,0)<<endl; cout<<derivative(rh op lh,0)<<endl;

#define CHECKpow(lh,rh) cout<<sadET::pow(lh,rh)<<endl; cout<<sadET::pow(rh,lh)<<endl;\
                        cout<<derivative(sadET::pow(lh,rh),0)<<endl; cout<<derivative(sadET::pow(rh,lh),0)<<endl;

#define CHECKun(op,x) cout<<sadET::op(x)<<endl; cout<<derivative(sadET::op(x),0)<<endl;

int main(){

    Variable<LD> x(2,0),y(3.2125,1);
    Constant<LD> c(0.1);
    
    CHECK(x,+,1)
    CHECK(x,-,1)
    CHECK(x,*,1)
    CHECK(x,/,1)

    CHECKpow(x,3.5)
    CHECKpow(1.2,1)

    CHECKpow(x,3.5)
    CHECKpow(1.2,1)

    CHECKun(exp,x)
    CHECKun(exp,1.2)

    CHECKun(log,x)
    CHECKun(log,1.2)


    CHECKun(sin,x)
    CHECKun(sin,1.2)


    CHECKun(cos,x)
    CHECKun(cos,1.2)

    cout<<derivative(3.33,0)<<endl;
    cout<<derivative(derivative(derivative(derivative(derivative(1,0),0),0),0),0)<<endl;
    

    // auto is you friend
    auto CC=sadET::log(x)+3;
    cout<<CC<<endl;
    


    return 0;
}