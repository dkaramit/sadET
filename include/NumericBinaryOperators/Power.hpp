#ifndef Pow_head
#define Pow_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>

#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericUnaryOperators/Negative.hpp>
#include<NumericUnaryOperators/Log.hpp>

namespace sadET{

/*------------------------Power---------------------------------*/

// this is the general case of Power
template<typename base, typename power,typename dummy=void>
class Power{
    public:
    
    base B;
    power P;

    using numType = typename common_type<typename base::numType,typename power::numType>::type;


    Power(const base &B, const power &P):B(B),P(P){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const {return std::pow(B.evaluate(at) , P.evaluate(at));}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const 
    {return pow(B,P-ONE<numType>) * ( P*B.derivative(wrt) + B*log(B)*P.derivative(wrt) ) ;}

    string str()const{return string("pow(") + print_expr(B) + string(",") + print_expr(P) + string(")");}

};

template<typename base, typename power, typename dummy=void>
inline auto pow(const base &B, const power &P){return Power<base,power>(B,P);}



}
#undef powNum
#endif