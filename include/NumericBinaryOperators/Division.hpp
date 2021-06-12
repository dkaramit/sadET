#ifndef Div_head
#define Div_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericBinaryOperators/Subtraction.hpp>
#include<NumericUnaryOperators/Negative.hpp>

namespace sadET{

/*------------------------Division---------------------------------*/

// this is the general case of Division
template<typename leftHand, typename rightHand, typename dummy=void>
class Division: public BinaryOperator<leftHand,rightHand>{
    public:

    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() / this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const
    {return this->LH.derivative(ID)/this->RH - this->LH*(this->RH.derivative(ID))/(this->RH*this->RH);}
};
//  operator/ returns a new instance of Division. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator/(const leftHand &LH, const rightHand &RH){return Division<leftHand,rightHand>(LH,RH);}



template<typename Expr, typename numericType> 
class Division<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH.evaluate() / this->RH;} 
    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID)/this->RH;}
};

template<typename numericType, typename Expr> 
class Division<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH / this->RH.evaluate();} 
    inline auto derivative(const unInt &ID)const{return  - this->LH*(this->RH.derivative(ID))/(this->RH*this->RH);}
};



}

#endif