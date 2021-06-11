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
//  operator+ returns a new instance of Multiplication. This happens at compile time, and it the final result 
// is evaluated when we aske for it. 
template<typename leftHand, typename rightHand>
inline auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}


/*---We can define different simplification rules based on template specification---*/
// An the derivative of "expression * constant" should only evaluate the derivative of the expression.
// this should make the evaluation a bit faster
template<typename Expr, typename LD>
class Multiplication<Expr,Constant<LD>>: public BinaryOperator<Expr,Constant<LD>>{
    public:
    using leftHand = Expr;
    using rightHand = Constant<LD>;

    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() * this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return this->LH.derivative(ID);}
};

template<typename Expr, typename LD>
class Multiplication<Constant<LD>,Expr>: public Multiplication<Expr,Constant<LD>>{
    public:
    using leftHand = Constant<LD>;
    using rightHand = Expr;
    Multiplication(const leftHand &LH, const rightHand &RH):Multiplication<rightHand,leftHand>(RH,LH){}
};


template<typename LD>
class Multiplication<Constant<LD>,Constant<LD>>: public BinaryOperator<Constant<LD>,Constant<LD>>{
    public:
    using leftHand = Constant<LD>;
    using rightHand = Constant<LD>;

    Multiplication(const leftHand &LH, const rightHand &RH):BinaryOperator<leftHand,rightHand>(LH,RH){}

    inline typename BinaryOperator<leftHand,rightHand>::numType evaluate()const
    {return this->LH.evaluate() * this->RH.evaluate();}

    inline auto derivative(const unInt &ID)const{return Constant<LD>(0) ;}
};


/*Use a macro for the rest :)*/
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

#endif