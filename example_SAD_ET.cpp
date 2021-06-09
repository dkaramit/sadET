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

    cout<<GenericExpression<Constant<LD>>::subExpression(c).evaluate()<<endl;
    
    cout<<GenericExpression<Variable<LD>>::subExpression(x).derivative().evaluate()<<endl;
    

    cout<<"sum"<<endl;
    cout<<(x+x).evaluate()<<endl;
    cout<<
        GenericExpression<
        binaryOperator<Addition<Variable<LD>,Variable<LD>>,Variable<LD>,Variable<LD>>
        >::subExpression(x+x).evaluate()
    <<endl;


    cout<<"derivative of sum"<<endl;
    cout<<(x+x).derivative().evaluate()<<endl;
    cout<<
        GenericExpression<
        binaryOperator<Addition<Variable<LD>,Variable<LD>>,Variable<LD>,Variable<LD>>
        >::subExpression(x+x).derivative().evaluate()
    <<endl;
   
    return 0;
}