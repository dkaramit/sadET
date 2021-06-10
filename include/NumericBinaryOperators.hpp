#ifndef NumBinOp_head
#define NumBinOp_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericUnaryOperators.hpp>

namespace sadET{
/*------------------------Addition---------------------------------*/
template<typename leftHand, typename rightHand>
class Addition{
    public:
    
    //this chooses the largest numerical type used in the expression 
    // (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
    using numType = typename largestType<leftHand,rightHand>::numType;

    leftHand LH;
    rightHand RH;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate()const{return LH.evaluate() + RH.evaluate();}

    template<unInt ID>
    inline auto derivative()const{return LH.template derivative<ID>() + RH.template derivative<ID>();}


    friend std::ostream& operator<<(std::ostream& os, const Addition &expr){os<<expr.evaluate();return os;} 
};

template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}




/*------------------------Multiplication---------------------------------*/
template<typename leftHand, typename rightHand>
class Multiplication{
    public:

    //this chooses the largest numerical type used in the expression 
    // (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
    using numType = typename largestType<leftHand,rightHand>::numType;

    leftHand LH;
    rightHand RH;

    Multiplication(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate()const{return LH.evaluate() * RH.evaluate();}

    template<unInt ID>
    inline auto derivative()const{return LH.template derivative<ID>()*RH + RH.template derivative<ID>()*LH;}

    friend std::ostream& operator<<(std::ostream& os, const Multiplication &expr){os<<expr.evaluate();return os;} 
};

template<typename leftHand, typename rightHand>
inline auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}


/*------------------------Subtraction---------------------------------*/
template<typename leftHand, typename rightHand>
class Subtraction{
    public:
    
    //this chooses the largest numerical type used in the expression 
    // (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
    using numType = typename largestType<leftHand,rightHand>::numType;

    leftHand LH;
    rightHand RH;

    Subtraction(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate()const{return LH.evaluate() - RH.evaluate();}

    template<unInt ID>
    inline auto derivative()const{return LH.template derivative<ID>() - RH.template derivative<ID>();}


    friend std::ostream& operator<<(std::ostream& os, const Subtraction &expr){os<<expr.evaluate();return os;} 
};

template<typename leftHand, typename rightHand>
inline auto operator-(const leftHand &LH, const rightHand &RH){return Subtraction<leftHand,rightHand>(LH,RH);}


/*------------------------Division---------------------------------*/
template<typename leftHand, typename rightHand>
class Division{
    public:
    
    //this chooses the largest numerical type used in the expression 
    // (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
    using numType = typename largestType<leftHand,rightHand>::numType;

    leftHand LH;
    rightHand RH;

    Division(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate()const{return LH.evaluate() / RH.evaluate();}

    template<unInt ID>
    inline auto derivative()const{
        return LH.template derivative<ID>()/RH - LH*(RH.template derivative<ID>())/(RH*RH) ;
        }


    friend std::ostream& operator<<(std::ostream& os, const Division &expr){os<<expr.evaluate();return os;} 
};

template<typename leftHand, typename rightHand>
inline auto operator/(const leftHand &LH, const rightHand &RH){return Division<leftHand,rightHand>(LH,RH);}




/*------------------------Power---------------------------------*/
template<typename base, typename power>
class Pow{
    public:
    
    //this chooses the largest numerical type used in the expression 
    // (eg numType == double if the two expressions have base::numType=int and base::numType=double)
    using numType = typename largestType<base,power>::numType;

    base B;
    power P;

    Pow(const base &B, const power &P):B(B),P(P){}

    inline auto evaluate()const{return std::pow(B.evaluate() , P.evaluate());}

    template<unInt ID>
    inline auto derivative()const{
        
        
        return  pow(B,P - positiveUn<numType>()) * (P*B.template derivative<ID>() + B*log(B)*P.template derivative<ID>() ) ;
        }


    friend std::ostream& operator<<(std::ostream& os, const Pow &expr){os<<expr.evaluate();return os;} 
};

template<typename base, typename power>
inline auto pow(const base &B, const power &P){return Pow<base,power>(B,P);}

};

#endif