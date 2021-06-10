#ifndef MISC_head
#define MISC_head


namespace sadET{

using unInt = unsigned int;


// take the derivative of an expression
template<typename Expr>
inline auto derivative(const Expr &expr, const unInt &ID){return expr.derivative(ID);}



//this chooses the largest numerical type used in the expression 
// (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
template<typename leftHand,typename rightHand>
struct largestType{
    using numType = typename std::conditional<(sizeof(typename leftHand::numType) >= sizeof(typename  rightHand::numType)),
                   typename  leftHand::numType, typename rightHand::numType>::type;

};


};

#endif