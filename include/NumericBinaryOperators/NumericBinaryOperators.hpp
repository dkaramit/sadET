#ifndef NumBinOp_head
#define NumBinOp_head
#include<iostream>
#include<cmath>

#include<misc.hpp>

namespace sadET{

template<typename leftHand, typename rightHand>
class BinaryOperator{
    protected:
    leftHand LH;
    rightHand RH;

    public:
    
    using numType = typename common_type<typename leftHand::numType,typename rightHand::numType>::type;
    
    BinaryOperator(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}
    virtual  numType evaluate() const=0;


};


}

#endif