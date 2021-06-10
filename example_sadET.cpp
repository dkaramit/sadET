#include<iostream>
#include<cmath>


#include<sadET.hpp>

// this is how you can define functions 
// (you can make it a class with overloaded operator() for more functionality)

template<typename T1, typename T2>
inline auto f(const T1 &x,const T2 &y)  {
    static sadET::Constant< typename sadET::largestType<T1,T2>::numType > c1(-1);

    return sadET::exp(-x*(y+c1))+sadET::log(x)*sadET::sin(y);
}



#ifndef LONG
    #define LONG
#endif
#define LD LONG double


using std::cout;
using std::endl;





int main(){


    sadET::Variable<LD,0> x(0.25);
    sadET::Variable<LD,1> y(3.2125);
    
    
    cout<< f(x,y) <<endl;

    // The drawback of this method is that the derivatives should be known at compile time.
    // The advandage is that it should be faster. 
    cout<<f(x,y).derivative<0>().derivative<0>()<<endl;
    cout<<f(x,y).derivative<0>().derivative<1>()<<endl;
    cout<<f(x,y).derivative<1>().derivative<0>()<<endl;
    cout<<f(x,y).derivative<1>().derivative<1>()<<endl;



    return 0;
}