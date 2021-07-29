#ifndef ExpOp_head
#define ExpOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>

namespace sadET{

/*------------------------Exp---------------------------------*/
template<typename Expr, typename dummy=void>
class Exp{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Exp(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::exp(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return Exp<Expr>(expr)*(expr.derivative(ID));}
    friend std::ostream& operator<<(std::ostream& os, const Exp &expr){os<<expr.evaluate();return os;} 
};

template<typename Expr>
inline auto exp(const Expr &expr){return Exp<Expr>(expr);}

template<typename Expr>
class Exp<Expr,typename enable_if<std::is_arithmetic<Expr>::value>::type>{
    public:

    using numType = Expr;
    
    Expr expr;

    Exp(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::exp(expr);}

    inline auto derivative(const unInt &ID)const{return Constant<Expr>(0);}
    friend std::ostream& operator<<(std::ostream& os, const Exp &expr){os<<expr.evaluate();return os;} 
};

}

#endif