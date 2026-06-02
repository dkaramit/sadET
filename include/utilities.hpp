#ifndef Deriv_head
#define Deriv_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Variable.hpp>

#define sadID static_cast<::sadET::IDType>(__COUNTER__)


namespace sadET{

template<variableType V, typename T> constexpr auto set (const V& var, const T& value) { return std::pair<IDType, T>{var.getID(), value}; }

template<typename... Pairs>
auto values(const Pairs&... pairs) {
    using numType = std::common_type_t<typename Pairs::second_type...>;

    return std::map<IDType, numType>{
        {pairs.first, static_cast<numType>(pairs.second)}...
    };
}

/*Evaluate expressions*/
template<typename Expr, typename numType> constexpr auto evaluate(const Expr &expr, const map<IDType,numType> &at){return expr.evaluate(at);}

/*Take derivatives of expressions*/
template<typename Expr, IDType WRT, typename T> constexpr auto derivative(const Expr &expr, const Variable<WRT, T>& wrt){return expr.derivative(wrt);}

template<typename Expr, typename Var1, typename... Vars> 
constexpr auto derivative(const Expr &expr, Var1 wrt, Vars... vars){
    return derivative(expr.derivative(wrt),vars...);
}

template<typename Expr> auto print_expr(const Expr &expr){return expr.str();}



}

#endif