#ifndef Sub_head
#define Sub_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericUnaryOperators/NumericUnaryOperators.hpp>

namespace sadET{

/*------------------------Subtraction---------------------------------*/
template<typename leftHand, typename rightHand>
class Subtraction: public BinaryOperator<leftHand,rightHand>{
    public:

    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() - this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID) - this->RH.derivative(ID);}
};

template<typename leftHand, typename rightHand>
inline auto operator-(const leftHand &LH, const rightHand &RH){return Subtraction<leftHand,rightHand>(LH,RH);}

template<typename Expr, typename LD>
class Subtraction<Expr,Constant<LD>>: public BinaryOperator<Expr,Constant<LD>>{
    public:
    using leftHand = Expr;
    using rightHand = Constant<LD>;

    Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() - this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}
};


template<typename Expr, typename LD>
class Subtraction<Constant<LD>,Expr>: public Subtraction<Expr,Constant<LD>>{
    public:
    using leftHand = Constant<LD>;
    using rightHand = Expr;
    Subtraction(const leftHand &LH, const rightHand &RH):Subtraction<rightHand,leftHand>(-1*RH,-1*LH){}
};


}

#endif