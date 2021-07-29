#ifndef Pow_head
#define Pow_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>

#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericUnaryOperators/Negative.hpp>
#include<NumericUnaryOperators/Log.hpp>

namespace sadET{

/*------------------------Power---------------------------------*/

// this is the general case of Power
template<typename base, typename power,typename dummy=void>
class Power: public BinaryOperator<base,power>{
    public:

    Power(const base &B, const power &P):BinaryOperator<base,power>(B,P){}

    inline typename BinaryOperator<base,power>::numType evaluate()const
    {return std::pow(this->LH.evaluate() , this->RH.evaluate());}

    inline auto derivative(const unInt &ID)const{return  
        pow(this->LH,this->RH -1) * 
        (this->RH*this->LH.derivative(ID) + this->LH*log(this->LH)*this->RH.derivative(ID) ) 
    ;}
};
//  operator- returns a new instance of Power. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename base, typename power, typename dummy=void>
inline auto pow(const base &B, const power &P){return Power<base,power>(B,P);}

template<typename Expr, typename numericType> 
class Power<Expr,numericType, 
typename enable_if<std::is_arithmetic<numericType>::value && (! std::is_arithmetic<Expr>::value),void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Power(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return std::pow(this->LH.evaluate(),this->RH);} 
    inline auto derivative(const unInt &ID)const
    {return pow(this->LH,this->RH -1) * this->RH*this->LH.derivative(ID);}
};

template<typename numericType, typename Expr> 
class Power<numericType, Expr, 
typename  enable_if<std::is_arithmetic<numericType>::value && (! std::is_arithmetic<Expr>::value),void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Power(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return std::pow(this->LH,this->RH.evaluate());} 
    inline auto derivative(const unInt &ID)const{return 
        pow(this->LH,this->RH) * (std::log(this->LH)*this->RH.derivative(ID) );}
};



template<typename LD1, typename LD2> 
class Power<LD1, LD2, 
typename  enable_if<std::is_arithmetic<LD1>::value && std::is_arithmetic<LD2>::value,void>::type >:
        public BinaryOperator<LD1,LD2>{ 
    public: 
    
    using  leftHand = LD1;
    using rightHand = LD2;
    using LD=typename largestType<LD1,LD2>::numType;

    Power(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline LD evaluate()const {return std::pow(this->LH,this->RH);} 
    inline auto derivative(const unInt &ID)const{return Constant<LD>(0);}
};

}
#undef powNum
#endif