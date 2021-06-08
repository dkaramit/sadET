#ifndef Var_head
#define Var_head

#include<GenericExpression.hpp>
#include<Constant.hpp>

// this is the varable class.
template<typename LD>
class Variable: public GenericExpression<LD,Variable<LD>>{
    LD value;

    // unsigned int ID; //at some point I am going to use an numeric value in order to get the derivatives wrt multiple variables
    public:
    // the standard constructor for a vector
    Variable(const LD &x):value(x){}

    LD evaluate()  const {return value;}
    LD& evaluate()  {return value;}

    // auto evaluate()  const {return Variable(value) ;}

    auto derivative()  const {return Constant<LD>(1); }

    // template<typename ExprType>
    // Variable(const GenericExpression<LD, ExprType> &other){
    //     const ExprType &v= other.subExpression();
    //     value=v.evaluate();
    // }


    // template<typename ExprType>
    // Variable& operator=(const GenericExpression<LD, ExprType> &other){
    //     const ExprType &v= other.subExpression();
    //     value=v.evaluate();

    //     return *this;
    // }

};





#endif
