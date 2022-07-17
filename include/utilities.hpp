#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Variable.hpp>

namespace sadET{

/*Evaluate expressions*/
template<typename Expr, typename numType>
constexpr auto evaluate(const Expr &expr, const map<IDType,numType> &at){return expr.evaluate(at);}

/*Take derivatives of expressions*/
template<typename Expr, typename numType, IDType ID>
constexpr auto derivative(const Expr &expr, const Variable<ID,numType> &wrt){return expr.derivative(wrt);}

}

#endif