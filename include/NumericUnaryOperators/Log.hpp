#ifndef LogOp_head
#define LogOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericBinaryOperators/Division.hpp>

namespace sadET{

/*------------------------natural Log---------------------------------*/
template<typename Expr, typename dummy=void>
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

template<typename Expr>
class Log<Expr,typename enable_if<std::is_arithmetic<Expr>::value>::type>{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = Expr;
    
    Expr expr;

    Log(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::log(expr);}

    inline auto derivative(const unInt &ID)const{return Constant<Expr>(0) ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Log &expr){os<<expr.evaluate();return os;} 

};



}

#endif