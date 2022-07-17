#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Variable.hpp>

namespace sadET{

/*Evaluate expressions*/
template<typename Expr, typename numType> constexpr auto evaluate(const Expr &expr, const map<IDType,numType> &at){return expr.evaluate(at);}



/*Take derivatives of expressions*/
template<typename Expr, typename Var> constexpr auto derivative(const Expr &expr, const Var &wrt){return expr.derivative(wrt);}

template<typename Expr, typename Var1, typename... Vars> 
constexpr auto derivative(const Expr &expr, Var1 wrt, Vars... vars){
    return derivative(expr.derivative(wrt),vars...);
}


}

#endif