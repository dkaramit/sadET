#ifndef BinOp_head
#define BinOp_head

#include<GenericExpression.hpp>
// #include<NumericBinaryOperators.hpp>

// Define a generic operator that takes two expressions (these are called binary operators)
template<typename LD, typename Operator, typename leftHand, typename rightHand>
class binaryOperator: public GenericExpression<LD, binaryOperator<LD, Operator,leftHand,rightHand> >{
    public:
    const leftHand &LH;
    const rightHand &RH;
    
    binaryOperator(const leftHand &LH, const rightHand &RH) :LH(LH),RH(RH){}

    auto evaluate() const {return Operator::evaluate(LH, RH); } 

    auto derivative() const {return Operator::derivative(LH,RH); }
    // auto derivative() const {return Operator::derivative(binaryOperator(LH,RH)); }


};




#endif