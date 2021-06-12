#ifndef Mul_head
#define Mul_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>

namespace sadET{
/*------------------------Multiplication---------------------------------*/

// this is the general case of Multiplication
template<typename leftHand, typename rightHand, typename dummy=void>
class Multiplication: public BinaryOperator<leftHand,rightHand>{
    public:

    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const{return this->LH.evaluate() * this->RH.evaluate();}
    inline auto derivative(const unInt &ID)const
    {return this->LH.derivative(ID)*this->RH + this->RH.derivative(ID)*this->LH;}
};
//  operator* returns a new instance of Multiplication. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}


template<typename Expr, typename numericType> 
class Multiplication<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH.evaluate() * this->RH;} 
    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}
};

template<typename numericType, typename Expr> 
class Multiplication<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH * this->RH.evaluate();} 
    inline auto derivative(const unInt &ID)const{return this->RH.derivative(ID);}
};


}

#endif