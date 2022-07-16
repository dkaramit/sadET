#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Variable.hpp>

namespace sadET{


/*Evaluate expressions*/
template<typename Expr, typename numType>
constexpr auto evaluate(const Expr &expr, const map<IDType,numType> &at){return expr.evaluate(at);}

/*Evaluate numbers*/
#define numEval(numT) template<typename numType> constexpr typename common_type<numT,numType>::type evaluate(const numT &expr, const map<IDType,numType> &at){\
    return expr;\
}
numEval(float)
numEval(double)
numEval(long double)
#undef numEval



/*Take derivatives of expressions*/
template<typename Expr, typename numType, IDType ID>
constexpr auto derivative(const Expr &expr, const Variable<ID,numType> &wrt){return expr.derivative(ID);}

/*Derivatives of numbers should return 0*/
#define numDer(numT) template<typename numType, IDType ID> constexpr typename common_type<numT,numType>::type derivative(const numT &expr, const Variable<ID,numType> &wrt){\
    return 0;\
}
numDer(float)
numDer(double)
numDer(long double)
#undef numDer



}

#endif