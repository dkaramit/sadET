#ifndef NumBinOp_head
#define NumBinOp_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericUnaryOperators/NumericUnaryOperators.hpp>

namespace sadET{

template<typename leftHand, typename rightHand>
class BinaryOperator{
    protected:
    leftHand LH;
    rightHand RH;

    public:
    
    using numType = typename largestType<leftHand,rightHand>::numType;
    
    BinaryOperator(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}
    virtual inline numType evaluate() const=0;
    friend std::ostream& operator<<(std::ostream& os, const BinaryOperator &expr)
    {os<<expr.evaluate();return os;} 
};






// /*------------------------Division---------------------------------*/
// template<typename leftHand, typename rightHand>
// class Division{
//     public:
    
//     //this chooses the largest numerical type used in the expression 
//     // (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
//     using numType = typename largestType<leftHand,rightHand>::numType;

//     leftHand LH;
//     rightHand RH;

//     Division(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

//     inline auto evaluate()const{return LH.evaluate() / RH.evaluate();}

//     inline auto derivative(const unInt &ID)const{
//         return LH.derivative(ID)/RH - LH*(RH.derivative(ID))/(RH*RH) ;
//         }


//     friend std::ostream& operator<<(std::ostream& os, const Division &expr){os<<expr.evaluate();return os;} 
// };

// template<typename leftHand, typename rightHand>
// inline auto operator/(const leftHand &LH, const rightHand &RH){return Division<leftHand,rightHand>(LH,RH);}




// /*------------------------Power---------------------------------*/
// template<typename base, typename power>
// class Pow{
//     public:
    
//     //this chooses the largest numerical type used in the expression 
//     // (eg numType == double if the two expressions have base::numType=int and base::numType=double)
//     using numType = typename largestType<base,power>::numType;

//     base B;
//     power P;

//     Pow(const base &B, const power &P):B(B),P(P){}

//     inline auto evaluate()const{return std::pow(B.evaluate() , P.evaluate());}

//     inline auto derivative(const unInt &ID)const{
//         Constant<numType> _un_(1);
        
//         return  pow(B,P -_un_) * (P*B.derivative(ID) + B*log(B)*P.derivative(ID) ) ;
//         }


//     friend std::ostream& operator<<(std::ostream& os, const Pow &expr){os<<expr.evaluate();return os;} 
// };

// template<typename base, typename power>
// inline auto pow(const base &B, const power &P){return Pow<base,power>(B,P);}

}

#endif