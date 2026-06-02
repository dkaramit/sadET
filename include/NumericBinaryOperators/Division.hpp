#ifndef Div_head
#define Div_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericOperators/Sum.hpp>
#include<NumericOperators/Product.hpp>

namespace sadET{

/*------------------------Division---------------------------------*/

// this is the general case of Division
template<typename leftHand, typename rightHand>
class Division{
    public:
        using is_sadET = void;

        leftHand LH;
        rightHand RH;

        using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

        constexpr Division(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

        template<typename T>
        inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) / RH.evaluate(at);}

        template<IDType WRT,typename T>
        constexpr auto derivative(const Variable<WRT,T> &wrt) const {return LH.derivative(wrt)/RH - LH*(RH.derivative(wrt))/(RH*RH);}

        string str()const{return string("(") + print_expr(LH) + string("/") + print_expr(RH) + string(")");}
};

template<sadExpr L, sadExpr R>
constexpr inline auto operator/(const L &LH, const R &RH){return Division<L,R>(LH,RH);}

// -------------- You can do something like this later--------------
// special case: Sum / expr
// template<sadExpr... L, sadExpr R>
// constexpr inline auto expand_division(const Sum<L...>& lhs, const R& rhs) {  
//     return std::apply( [&](const auto& ... term) { return  make_sum((term/rhs)...); }, lhs.terms ); 
// }


}

#endif