#ifndef Var_head
#define Var_head

#include<GenericExpression.hpp>
#include<Constant.hpp>

// this is the varable class.
template<typename LD>
class Variable: public GenericExpression<Variable<LD>>{
    LD value;

    // unsigned int ID; //at some point I am going to use an numeric value in order to get the derivatives wrt multiple variables
    public:
    Variable(const LD &x):value(x){}

    LD evaluate()  const {return value;}
    LD& evaluate()  {return value;}

    auto derivative()  const {return Constant<LD>(1); }
    // LD derivative()  const {return 1;}

};





#endif
