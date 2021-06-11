#ifndef LogOp_head
#define LogOp_head
#include<cmath>

#include<NumericBinaryOperators/Division.hpp>

namespace sadET{

/*------------------------natural Log---------------------------------*/
template<typename Expr>
class Log{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Log(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::log(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return expr.derivative(ID)/expr ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Log &expr){os<<expr.evaluate();return os;} 

};

template<typename Expr>
inline auto log(const Expr &expr){return Log<Expr>(expr);}




}

#endif