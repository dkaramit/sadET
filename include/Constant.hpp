#ifndef Const_head
#define Const_head

#include<GenericExpression.hpp>

template<typename LD>
class Constant: public GenericExpression<Constant<LD>>{
    LD value;
    public:

    Constant(const LD &x):value(x){}
    LD evaluate()  const {return value;}
    auto derivative()  const {return Constant<LD>(0);}
    // LD derivative()  const {return 0;}

};

#endif
