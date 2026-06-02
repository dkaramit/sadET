#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Variable.hpp>

namespace sadET{



/*Evaluate expressions*/
template<typename Expr, typename numType> constexpr auto evaluate(const Expr &expr, const map<IDType,numType> &at){return expr.evaluate(at);}

/*Take derivatives of expressions*/
template<typename Expr, IDType WRT, typename T> constexpr auto derivative(const Expr &expr, const Variable<WRT, T>& wrt){return expr.derivative(wrt);}

template<typename Expr, typename Var1, typename... Vars> 
constexpr auto derivative(const Expr &expr, Var1 wrt, Vars... vars){
    return derivative(expr.derivative(wrt),vars...);
}

template<typename Expr> auto print_expr(const Expr &expr){return expr.str();}


// #define SADET_VAR(LD) sadET::Variable<__COUNTER__, LD>{}


}

#endif