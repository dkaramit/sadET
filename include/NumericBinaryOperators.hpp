#ifndef NumOp_head
#define NumOp_head

#include<GenericBinaryOperator.hpp>


/*------------------------Addition---------------------------------*/
template<typename LD, typename leftHand, typename rightHand>
class Addition{
    public:

    inline static auto evaluate (const leftHand &LH, const rightHand &RH) {
        return LH.evaluate()+RH.evaluate();
    }

    inline static auto derivative(const leftHand &LH, const rightHand &RH){
        // return LH.derivative() + RH.derivative() ;
        return operator+(LH.derivative(),RH) ;
    }
};

template<typename LD, typename leftHand, typename rightHand>
auto operator+(const GenericExpression<LD,leftHand> &LH, const GenericExpression<LD,rightHand> &RH){
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
auto operator*(const GenericExpression<LD,leftHand> &LH, const GenericExpression<LD,rightHand> &RH){
    return binaryOperator<LD,Multiplication<LD, leftHand,rightHand>,leftHand,rightHand>(LH.subExpression(),RH.subExpression());
}


#endif