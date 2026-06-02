#ifndef LogOp_head
#define LogOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericBinaryOperators/Division.hpp>

namespace sadET{

/*------------------------natural Log---------------------------------*/
template<typename Expr>
class Log{
    public:
    using is_sadET = void;
    using numType = typename Expr::numType;
    
    Expr expr;

    constexpr Log(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::log(expr.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return expr.derivative(wrt)/expr ;}


    string str()const{return string("log(") + print_expr(expr) + string(")");}

};

template<sadExpr Expr>
constexpr inline auto log(const Expr &expr){return Log<Expr>(expr);}


}

#endif