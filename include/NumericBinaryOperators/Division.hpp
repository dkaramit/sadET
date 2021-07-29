#ifndef Div_head
#define Div_head
#include<iostream>
#include<cmath>

#include<misc.hpp>
#include<NumericBinaryOperators/NumericBinaryOperators.hpp>
#include<NumericBinaryOperators/Addition.hpp>
#include<NumericBinaryOperators/Multiplication.hpp>
#include<NumericBinaryOperators/Subtraction.hpp>
#include<NumericUnaryOperators/NumericUnaryOperators.hpp>

namespace sadET{

/*------------------------Division---------------------------------*/

// this is the general case of Addition
template<typename leftHand, typename rightHand>
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

/*Use  macros for the rest numeric types :)*/
#define divNum(numericType) \
    template<typename Expr> \
    class Division<Expr,numericType>: public BinaryOperator<Expr,numericType>{ \
        \
        public: \
        \
        using leftHand = Expr;\
        using rightHand = numericType;\
        \
        Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH.evaluate() / this->RH;} \
        \
        inline auto derivative(const unInt &ID)const\
        {return this->LH.derivative(ID)/this->RH;}\
    };\
    \
    template<typename Expr> \
    class Division<numericType,Expr>: public BinaryOperator<numericType,Expr>{ \
        \
        public: \
        using leftHand  = numericType;\
        using rightHand = Expr;\
        \
        Division(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH / this->RH.evaluate();} \
        \
        inline auto derivative(const unInt &ID)const\
        {return  - this->LH*(this->RH.derivative(ID))/(this->RH*this->RH);}\
    };\
 
divNum(float);
divNum(double);
divNum(long double);
divNum(int);
divNum(unsigned int);



}
#undef divNum
#endif