#ifndef Const_head
#define Const_head

#include<iostream>

#include<GenericExpression.hpp>

// this is the vector class. It will be used to define vectors that can be added and multiplied.
template<typename LD>
class Constant: public GenericExpression<LD,Constant<LD>>{
    LD value;
    public:

    // the standard constructor for a vector
    Constant(const LD &x):value(x){}
    LD evaluate()  const {return value;}
    Constant<LD> derivative()  const {return Constant<LD>(0);}

};

#endif
