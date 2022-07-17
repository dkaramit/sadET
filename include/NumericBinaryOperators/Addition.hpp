#ifndef Add_head
#define Add_head
#include<iostream>
#include<cmath>

#include<misc.hpp>

namespace sadET{
/*------------------------Addition---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand, typename dummy=void>
class Addition{
    leftHand LH;
    rightHand RH;

    public:
    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) + RH.evaluate(at);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return LH.derivative(wrt) + RH.derivative(wrt);}
};
//  operator+ returns a new instance of Addition. This happens at compile time, and it the final result is evaluated when we ask for it. 
template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}

/*===================================Specializations===================================*/

}


#endif