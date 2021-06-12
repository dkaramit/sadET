#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>

namespace sadET{

using unInt = unsigned int;


// take the derivative of an expression
template<typename Expr>
auto derivative(const Expr &expr, const unInt &ID){return expr.derivative(ID);}


// overload derivative for numeric types (this is easier than eneble_if) 
#define numDer(type) auto derivative(const type &expr, const unInt &ID){return Constant<type>(0);}

numDer(float)
numDer(double)
numDer(long double)
numDer(int)
numDer(long int)

#undef numDer

}

#endif