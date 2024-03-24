#ifndef NegOp_head
#define NegOp_head
#include<cmath>


namespace sadET{

/*------------------------Negative---------------------------------*/

template<typename Expr, typename dummy=void>
class Neg{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Neg(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return -expr.evaluate(at);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return -expr.derivative(wrt);}

    string str()const{return string("-(") + print_expr(expr) + string(")");}
};


template<typename Expr>
inline auto operator-(const Expr &expr){return Neg<Expr>(expr);}

}


#endif