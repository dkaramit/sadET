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
template<typename leftHand, typename rightHand>
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


/*Use  macros for the rest numeric types :)*/
#define mulNum(numericType) \
    template<typename Expr> \
    class Multiplication<Expr,numericType>: public BinaryOperator<Expr,numericType>{ \
        public: \
        using leftHand = Expr;\
        using rightHand = numericType;\
        Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){} \
        inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const \
        {return this->LH.evaluate() * this->RH;} \
        inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}\
    };\
    template<typename Expr> \
    class Multiplication<numericType,Expr>: public Multiplication<Expr,numericType>{ \
        public: \
        using leftHand = numericType;\
        using rightHand = Expr;\
        Multiplication(const leftHand &LH, const rightHand &RH):Multiplication<rightHand,leftHand>(RH,LH){} \
    };\



mulNum(float);
mulNum(double);
mulNum(long double);
mulNum(int);
mulNum(unsigned int);

}

#undef mulNum
#endif