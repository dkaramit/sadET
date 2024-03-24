#ifndef Div_head
#define Div_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericBinaryOperators/Subtraction.hpp>

namespace sadET{

/*------------------------Division---------------------------------*/

// this is the general case of Division
template<typename leftHand, typename rightHand, typename dummy=void>
class Division{
    public:

    leftHand LH;
    rightHand RH;

    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

    Division(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) / RH.evaluate(at);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return LH.derivative(wrt)/RH - LH*(RH.derivative(wrt))/(RH*RH);}

    string str()const{return string("(") + print_expr(LH) + string("/") + print_expr(RH) + string(")");}


};

template<typename leftHand, typename rightHand>
inline auto operator/(const leftHand &LH, const rightHand &RH){return Division<leftHand,rightHand>(LH,RH);}



}
#undef divNum
#endif