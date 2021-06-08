#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;


#include<SAD_ET.hpp>

#ifndef LONG
    #define LONG
#endif
#define LD LONG double


int main(){

    Variable<LD> x(11);
    Constant<LD> c(1);
    //this is the reason (x+x).derivative().evaluation() does not work!
    // figure out how to do it without subExpression...
    cout<<GenericExpression<LD,Constant<LD>>(x.derivative()).subExpression().evaluate()<<endl;
    cout<<GenericExpression<LD,Constant<LD>>(c).subExpression().evaluate()<<endl;

    // cout<<(x+x).evaluate()<<endl;
    // cout<<(x+c).evaluate()<<endl;
    // cout<<(x*x).evaluate()<<endl;
    // cout<<((c+x*x)+c*x).evaluate()<<endl;

    // cout<<typeid(x.derivative()).name()<<endl;
    // cout<<typeid(x.derivative() + x).name()<<endl;

    // cout<< typeid((x+x+x).evaluate()).name()<<endl;
    // cout<< typeid(c + c).name()<<endl;
    // cout<< typeid((x.derivative() + x.derivative())).name()<<endl;
    // cout<< typeid((x + x + x).derivative()).name()<<endl;

    // cout<<(x+x).evaluate()<<endl;
    // cout<<(c+c).evaluate()<<endl;
    // cout<<(x.derivative()+x.derivative()).evaluate()<<endl;
    
    // cout<<(x+x).derivative().evaluate()<<endl;

    // (x+x).derivative().evaluate() should expand to this:
    // cout<<(binaryOperator<LD,
    // Addition<LD,Constant<LD>,Constant<LD>>,
    // Constant<LD>,Constant<LD>>(c.derivative(),c.derivative())).evaluate()<<endl;
 
    // cout<<typeid( Addition<LD,Variable<LD>,Variable<LD>>::derivative(x,x) ).name()<<endl;
    // cout << typeid( (x+x).derivative() ).name()<< endl;
    // cout << typeid( x.derivative()+x.derivative() ).name()<< endl;
    // cout << typeid( (c+c) ).name()<< endl;
   
    // cout <<(x+x).derivative().evaluate()<< endl;
    // cout<<Addition<LD,Variable<LD>,Variable<LD>>::derivative(x,x).evaluate()<<endl;
    // cout <<(x.derivative()+x.derivative()).evaluate()<< endl;
    // cout <<(c+c).evaluate()<< endl;
   
    return 0;
}