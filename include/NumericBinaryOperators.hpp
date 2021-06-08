#ifndef NumOp_head
#define NumOp_head

#include<iostream>

#include<GenericExpression.hpp>
#include<GenericBinaryOperator.hpp>

/*------------------------Addition---------------------------------*/
template<typename LD, typename leftHand, typename rightHand>
class Addition{
    public:
    static LD evaluate (const leftHand &LH, const rightHand &RH) {
        return LH.evaluate()+RH.evaluate();
    }
};

template<typename LD, typename leftHand, typename rightHand>
binaryOperator<LD, Addition<LD, leftHand,rightHand>,leftHand,rightHand> operator+(const GenericExpression<LD,leftHand> &LH, const GenericExpression<LD,rightHand> &RH){
    return binaryOperator<LD,Addition<LD, leftHand,rightHand>,leftHand,rightHand>(LH.subExpression(),RH.subExpression());
}

 


/*------------------------Multiplication---------------------------------*/
template<typename LD, typename leftHand, typename rightHand>
class Multiplication{
    public:
    static LD evaluate (const leftHand &LH, const rightHand &RH) {
        return LH.evaluate()*RH.evaluate();
    }
};

template<typename LD, typename leftHand, typename rightHand>
binaryOperator<LD, Multiplication<LD, leftHand,rightHand>,leftHand,rightHand> operator*(const GenericExpression<LD,leftHand> &LH, const GenericExpression<LD,rightHand> &RH){
    return binaryOperator<LD,Multiplication<LD, leftHand,rightHand>,leftHand,rightHand>(LH.subExpression(),RH.subExpression());
}

 

#endif