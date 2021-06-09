#ifndef NumUnOp_head
#define NumUnOp_head
#include<cmath>
#include<NumericBinaryOperators.hpp>

/*------------------------Exp---------------------------------*/
template<typename Expr>
class Exp{
    public:

    Expr expr;

    Exp(const Expr &expr):expr(expr){}

    inline auto evaluate () {return std::exp(expr.evaluate());}

    inline auto derivative(){return Exp<Expr>(expr)*(expr.derivative());}
};

template<typename Expr>
auto exp(const Expr &expr){return Exp<Expr>(expr);}

#endif