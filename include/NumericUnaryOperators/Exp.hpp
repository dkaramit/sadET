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

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::exp(expr.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return Exp<Expr>(expr)*(expr.derivative(wrt)) ;}


    string str()const{return string("exp(") + print_expr(expr) + string(")");}

};

template<typename Expr>
inline auto exp(const Expr &expr){return Exp<Expr>(expr);}

/*===================================Specializations/Simplifications===================================*/
// This is how you define Exp for numbers. Not very useful for the moment.


template<typename Expr>
class Exp<Expr,typename enable_if<std::is_arithmetic<Expr>::value>::type>{
    public:

    using numType = Expr;
    
    Expr expr;

    Exp(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::exp(expr);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return ZERO<numType> ;}

    string str()const{return string(std::exp(expr)) ;}
};

}

#endif