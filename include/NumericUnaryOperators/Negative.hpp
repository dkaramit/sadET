#ifndef NegOp_head
#define NegOp_head
#include<cmath>

#include<NumericBinaryOperators/Multiplication.hpp>

namespace sadET{

/*------------------------Negative---------------------------------*/
template<typename Expr>
class Neg{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Neg(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return -1*expr.evaluate();}

    inline auto derivative(const unInt &ID)const{return -1*(expr.derivative(ID));}
    
    friend std::ostream& operator<<(std::ostream& os, const Neg &expr){os<<expr.evaluate();return os;} 
};

template<typename Expr>
inline auto operator-(const Expr &expr){return Neg<Expr>(expr);}

}


#endif