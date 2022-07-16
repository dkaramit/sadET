#ifndef Mul_head
#define Mul_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>

namespace sadET{
// this is the general case of Multiplication
template<typename leftHand, typename rightHand, typename dummy=void>
class Multiplication{
    leftHand LH;
    rightHand RH;

    public:
    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

    Multiplication(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) * RH.evaluate(at);}

    constexpr auto derivative(const IDType &wrt)const{return LH.derivative(wrt)*RH + LH*RH.derivative(wrt);}
};
//  operator+ returns a new instance of Multiplication. This happens at compile time, and it the final result is evaluated when we ask for it. 
template<typename leftHand, typename rightHand>
inline auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}

/*===================================Specializations===================================*/

template<typename leftHand, typename rightHand>
class Multiplication<leftHand,rightHand,typename std::enable_if<std::is_arithmetic<leftHand>::value,void>::type>{
    leftHand LH;
    rightHand RH;

    public:
    using numType = typename common_type<leftHand,typename rightHand::numType>::type;

    Multiplication(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH * RH.evaluate(at);}

    constexpr auto derivative(const IDType &wrt)const{return LH*RH.derivative(wrt);}
};

template<typename leftHand, typename rightHand>
class Multiplication<leftHand,rightHand,typename std::enable_if<std::is_arithmetic<rightHand>::value,void>::type>{
    leftHand LH;
    rightHand RH;

    public:
    using numType = typename common_type<typename leftHand::numType,rightHand>::type;

    Multiplication(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at)*RH;}

    constexpr auto derivative(const IDType &wrt)const{return LH.derivative(wrt)*RH;}
};


}

#undef mulNum
#endif