#include<iostream>
#include<cmath>

#include<sadET.hpp>

using std::cout;
using std::endl;
using sadET::evaluate;
using sadET::derivative;


 int main(){
    // constant like:
    sadET::Constant<double,33> c;
    // using sadID to produce unique IDs,  declare variables as 
    sadET::Variable<sadID,double> x;
    sadET::Variable<sadID,long double> y;
    

    std::map<sadET::IDType,double> at= {{x.getID(),1.2},{y.getID(),10.8}} ;

    
    auto s= x+y+c;
    auto p=x*s*y;
    
    
    // cout << std::tuple_size_v<decltype((s+x).terms)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((x+s).terms)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((s+s).terms)> << "\n";//this returns 6 instead of 2!
    
    // cout << std::tuple_size_v<decltype((s-x).terms)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((x-s).terms)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((s-s).terms)> << "\n";//this returns 6 instead of 2!
    
    
    // cout << std::tuple_size_v<decltype((p*x).factors)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((x*p).factors)> << "\n";//this returns 4 instead of 2!
    // cout << std::tuple_size_v<decltype((p*p).factors)> << "\n";//this returns 6 instead of 2!

    
    // cout<< evaluate(c,at)  <<"\n";
    // cout<< evaluate(x,at)  <<"\n";
    // cout<< evaluate(y,at)  <<"\n";
    
    // cout<< evaluate(s,at)  <<"\n";
    // cout<< evaluate(p,at)  <<"\n";
    
    // cout<< evaluate( derivative(p*p,x) ,at)  <<"\n";
    // cout<< evaluate( derivative(p*p,y) ,at)  <<"\n";
    // cout<< evaluate( derivative(p*p,x,x) ,at)  <<"\n";
    // cout<< evaluate( derivative(p*p,y,y) ,at)  <<"\n";
    // cout<< evaluate( derivative(p*p,x,y) ,at)  <<"\n";


    // cout<< evaluate( derivative(p+p*s+s,x) ,at)  <<"\n";
    // cout<< evaluate( derivative(p+p*s+s,y) ,at)  <<"\n";
    // cout<< evaluate( derivative(p+p*s+s,x,x) ,at)  <<"\n";
    // cout<< evaluate( derivative(p+p*s+s,y,y) ,at)  <<"\n";
    // cout<< evaluate( derivative(p+p*s+s,x,y) ,at)  <<"\n";

    // this should be 0.000306337
    cout<< evaluate( derivative(pow(s-exp(-p/c)-x+sin(s-c-cos(p))+p*p,sin(log(s)))/log( derivative( p+s*y/c,y,y )),x,y) ,at)  <<"\n";
    // cout<< print_expr( derivative(pow(s-exp(-p)-x+sin(s-cos(p))+p*p,sin(log(s)))/log(p+s*y),x,y) )  <<"\n";

   // cout<<print_expr(s)<<"\n";

    return 0;
}