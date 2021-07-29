#ifndef Pow_head
#define Pow_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericUnaryOperators/NumericUnaryOperators.hpp>
#include<NumericUnaryOperators/Negative.hpp>

namespace sadET{

/*------------------------Power---------------------------------*/

// this is the general case of Power
template<typename base, typename power>
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
template<typename base, typename power>
inline auto pow(const base &B, const power &P){return Power<base,power>(B,P);}

/*Use  macros for the rest numeric types :)*/
#define powNum(numericType) \
    template<typename Expr> \
    class Power<Expr,numericType>: public BinaryOperator<Expr,numericType>{ \
        \
        public: \
        \
        using leftHand = Expr;\
        using rightHand = numericType;\
        \
        Power(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<Expr,numericType>::numType evaluate()const\
        {return std::pow(this->LH.evaluate() , this->RH);}\
        \
        inline auto derivative(const unInt &ID)const{return \
            pow(this->LH,this->RH -1) * this->RH*this->LH.derivative(ID);\
        }\
    };\
    template<typename Expr> \
    class Power<numericType,Expr>: public BinaryOperator<numericType,Expr>{ \
        \
        public: \
        \
        using leftHand = numericType;\
        using rightHand = Expr;\
        \
        Power(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const\
        {return std::pow(this->LH , this->RH.evaluate());}\
        \
        inline auto derivative(const unInt &ID)const{return \
        pow(this->LH,this->RH) * (std::log(this->LH)*this->RH.derivative(ID) ) ;\
        }\
    };\
 
powNum(float);
powNum(double);
powNum(long double);
powNum(int);
powNum(unsigned int);



}
#undef powNum
#endif