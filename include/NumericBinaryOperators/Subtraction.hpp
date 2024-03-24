#ifndef Sub_head
#define Sub_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericUnaryOperators/Negative.hpp>

namespace sadET{

/*------------------------Subtraction---------------------------------*/

// this is the general case of Subtraction
template<typename leftHand, typename rightHand, typename dummy=void>
class Subtraction{
    public:    
    leftHand LH;
    rightHand RH;

    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

    Subtraction(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}


    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) - RH.evaluate(at);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return LH.derivative(wrt) - RH.derivative(wrt);}

    string str()const{return string("(") + print_expr(LH) + string("-") + print_expr(RH) + string(")");}

};
 
template<typename leftHand, typename rightHand>
inline auto operator-(const leftHand &LH, const rightHand &RH){return Subtraction<leftHand,rightHand>(LH,RH);}



}
#undef subNum
#endif