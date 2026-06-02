#ifndef TrigOp_head
#define TrigOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericOperators/Sum.hpp>
#include<NumericUnaryOperators/Negative.hpp>

namespace sadET{

/*------------------------Sin---------------------------------*/
template<typename Expr>
class Sin{
    public:
    using is_sadET = void;
    using numType = typename Expr::numType;

    Expr expr;

    Sin(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::sin(expr.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return cos(expr)*expr.derivative(wrt);}

    string str()const{return string("sin(") + print_expr(expr) + string(")");}

};

template<sadExpr Expr>
inline auto sin(const Expr &expr){return Sin<Expr>(expr);}


/*------------------------Cos---------------------------------*/
template<typename Expr>
class Cos{
    public:
    using is_sadET = void;
    using numType = typename Expr::numType;
    
    Expr expr;

    Cos(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::cos(expr.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return -sin(expr)*expr.derivative(wrt);}

    string str()const{return string("cos(") + print_expr(expr) + string(")");}

};

template<sadExpr Expr>
inline auto cos(const Expr &expr){return Cos<Expr>(expr);}



}

#endif