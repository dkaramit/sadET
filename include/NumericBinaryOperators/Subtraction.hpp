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
template<typename leftHand, typename rightHand>
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

/*Use  macros for the rest numeric types :)*/
#define subNum(numericType) \
    template<typename Expr> \
    class Subtraction<Expr,numericType>: public BinaryOperator<Expr,numericType>{ \
        \
        public: \
        \
        using leftHand = Expr;\
        using rightHand = numericType;\
        \
        Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH.evaluate() - this->RH;} \
        \
        inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}\
    };\
    \
    template<typename Expr> \
    class Subtraction<numericType,Expr>: public BinaryOperator<numericType,Expr>{ \
        \
        public: \
        using leftHand  = numericType;\
        using rightHand = Expr;\
        \
        Subtraction(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH - this->RH.evaluate();} \
        \
        inline auto derivative(const unInt &ID)const{return -this->RH.derivative(ID);}\
    };\
 
subNum(float);
subNum(double);
subNum(long double);
subNum(int);
subNum(unsigned int);



}
#undef subNum
#endif