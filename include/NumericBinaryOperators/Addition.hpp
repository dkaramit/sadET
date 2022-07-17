#ifndef Add_head
#define Add_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>

namespace sadET{
/*------------------------Addition---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand, typename dummy=void>
class Addition{
    public:
    
    leftHand LH;
    rightHand RH;

    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    template<typename T>
    inline auto evaluate(const map<IDType,T> &at)const{return LH.evaluate(at) + RH.evaluate(at);}

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {return LH.derivative(wrt) + RH.derivative(wrt);}

    string str()const{return string("(") + print_expr(LH) + string("+") + print_expr(RH) + string(")");}

};
//  operator+ returns a new instance of Addition. This happens at compile time, and it the final result is evaluated when we ask for it. 
template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition(LH,RH);}

/*===================================Specializations/Simplifications===================================*/

// Sort variables: 
// Variable<1> + Variable<0> -> Variable<0> + Variable<1>
template<typename leftHand, typename rightHand, IDType IDL, IDType IDR>
inline auto operator+(const Variable<IDL,leftHand> &LH, const Variable<IDR,rightHand> &RH){
    if constexpr(IDR<IDL){return Addition(RH,LH);}  
    else return Addition(LH,RH); 
}


// Define how the addition happens: 
// LH+(RH1+RH2) -> (LH+RH1)+RH2
template<typename leftHand, typename rightHand1, typename rightHand2>
inline auto operator+(const leftHand &LH, const Addition<rightHand1,rightHand2> &RH){  return (LH+RH.LH)+RH.RH; }

// Constant<leftHand, ValueL> + Constant<rightHand, ValueR> -> Constant<common_type, ValueL+ValueR> 
template<typename leftHand, templateP<leftHand> ValueL, typename rightHand, templateP<rightHand> ValueR>
inline auto operator+(const Constant<leftHand, ValueL> &LH, const Constant<rightHand, ValueR> &RH){
    using numType = typename common_type<leftHand,rightHand>::type;
    return Constant<numType, ValueL.value+ValueR.value>();
}

// Move all constants to the left:
// expression + Constant<rightHand, Value> -> Constant<rightHand, Value> + expression 
template<typename leftHand, typename rightHand, templateP<rightHand> ValueR>
inline auto operator+(const leftHand &LH, const Constant<rightHand, ValueR> &RH){return RH+LH;}





}



#endif