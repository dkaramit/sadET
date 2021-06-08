#ifndef BinOp_head
#define BinOp_head

#include<iostream>

#include<GenericExpression.hpp>

// Define a generic operator that takes two expressions (these are called binary operators)
template<typename LD, typename Operator, typename leftHand, typename rightHand>
class binaryOperator: public GenericExpression<LD, binaryOperator<LD, Operator,leftHand,rightHand> >{
    const leftHand &LH;
    const rightHand &RH;
    public:
    
    binaryOperator(const leftHand &LH, const rightHand &RH) :LH(LH),RH(RH){}

    LD evaluate() const {return Operator::evaluate(LH, RH); } 
};


#endif