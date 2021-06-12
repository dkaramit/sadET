#ifndef Add_head
#define Add_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>

namespace sadET{
/*------------------------Addition---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand, typename dummy=void>
class Addition: public BinaryOperator<leftHand,rightHand>{
    public:

    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() + this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID) + this->RH.derivative(ID);}
};
//  operator+ returns a new instance of Addition. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}


template<typename Expr, typename numericType> 
class Addition<Expr,numericType, typename enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<Expr,numericType>{ 
    public: 
    using leftHand = Expr;
    using rightHand = numericType;
    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH.evaluate() + this->RH;} 
    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}
};

template<typename numericType, typename Expr> 
class Addition<numericType, Expr, typename  enable_if<std::is_arithmetic<numericType>::value,void>::type >:
        public BinaryOperator<numericType,Expr>{ 
    public: 
    using  leftHand = numericType;
    using rightHand = Expr;
    Addition(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} 
    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const 
    {return this->LH + this->RH.evaluate();} 
    inline auto derivative(const unInt &ID)const{return this->RH.derivative(ID);}
};



}

#endif