#ifndef Sub_head
#define Sub_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericUnaryOperators/Negative.hpp>

namespace sadET{

/*------------------------Subtraction---------------------------------*/

// this is the general case of Subtraction
template<typename leftHand, typename rightHand, typename dummy=void>
class Subtraction: public BinaryOperator<leftHand,rightHand>{
    public:

    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() - this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID) - this->RH.derivative(ID);}
};
//  operator- returns a new instance of Subtraction. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator-(const leftHand &LH, const rightHand &RH){return Subtraction<leftHand,rightHand>(LH,RH);}

template<typename Expr, typename numericType> 
class Subtraction<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH.evaluate() - this->RH;} 
    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}
};

template<typename numericType, typename Expr> 
class Subtraction<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH - this->RH.evaluate();} 
    inline auto derivative(const unInt &ID)const{return -this->RH.derivative(ID);}
};




}
#undef subNum
#endif