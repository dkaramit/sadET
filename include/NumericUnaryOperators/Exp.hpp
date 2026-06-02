#ifndef ExpOp_head
#define ExpOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericOperators/Product.hpp>

namespace sadET{

/*------------------------Exp---------------------------------*/
template<typename Expr>
class Exp{
    public:
    using is_sadET = void;
    using numType = typename Expr::numType;
    
    Expr expr;

    constexpr Exp(const Expr &expr):expr(expr){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return std::exp(expr.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return Exp<Expr>(expr)*(expr.derivative(wrt)) ;}


    string str()const{return string("exp(") + print_expr(expr) + string(")");}

};

template<sadExpr Expr>
constexpr inline auto exp(const Expr &expr){return Exp<Expr>(expr);}

}

#endif