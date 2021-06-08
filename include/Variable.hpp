#ifndef Var_head
#define Var_head

#include<iostream>

#include<GenericExpression.hpp>
#include<Constant.hpp>

// this is the vector class. It will be used to define vectors that can be added and multiplied.
template<typename LD>
class Variable: public GenericExpression<LD,Variable<LD>>{
    LD value;

    // unsigned int ID; //at some point I am going to use an numeric value in order to get the derivatives wrt multiple variables
    public:

    // the standard constructor for a vector
    Variable(const LD &x):value(x){}
    LD evaluate()  const {return value;}
    LD& evaluate()  {return value;}

    Constant<LD> derivative()  const {return Constant<LD>(1);}

    template<typename ExprType>
    Variable(const GenericExpression<LD, ExprType> &other){
        const ExprType &v= other.subExpression();
        value=v.evaluate();
    }


    // constructor that takes any Expression and makes it a vector
    template<typename ExprType>
    Variable& operator=(const GenericExpression<LD, ExprType> &other){
        const ExprType &v= other.subExpression();
        value=v.evaluate();

        return *this;
    }

};

#endif
