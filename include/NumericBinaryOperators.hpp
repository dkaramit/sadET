#ifndef NumOp_head
#define NumOp_head

#include<GenericBinaryOperator.hpp>
#include<GenericExpression.hpp>


/*------------------------Addition---------------------------------*/
template<typename leftHand, typename rightHand>
class Addition{
    public:

    inline static auto evaluate (const leftHand &LH, const rightHand &RH) {
        return LH.evaluate()+RH.evaluate();
    }

    inline static auto derivative(const leftHand &LH, const rightHand &RH){
        return LH.derivative() + RH.derivative() ;
    }
};

template<typename leftHand, typename rightHand>
auto operator+(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
    return binaryOperator<Addition< leftHand,rightHand>,leftHand,rightHand>
    (GenericExpression<leftHand>::subExpression(LH),GenericExpression<rightHand>::subExpression(RH));
}

/*------------------------Multiplication---------------------------------*/
// template<typename leftHand, typename rightHand>
// class Multiplication{
//     public:
//     static auto evaluate (const leftHand &LH, const rightHand &RH) {
//         return LH.evaluate()*RH.evaluate();
//     }
// };



// template<typename leftHand, typename rightHand>
// auto operator*(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
//     return binaryOperator<Multiplication< leftHand,rightHand>,leftHand,rightHand>
//     (GenericExpression<leftHand>::subExpression(LH),GenericExpression<rightHand>::subExpression(RH));
// }


#endif