#ifndef MISC_head
#define MISC_head


namespace sadET{

using unInt = unsigned int;


// take the derivative of an expression
template<typename Expr>
inline auto derivative(const Expr &expr, const unInt &ID){return expr.derivative(ID);}


template<bool C, typename T1, typename T2>
struct IF{using type=T1;};

template<typename T1, typename T2>
struct IF<false,T1,T2>{using type=T2;};


//this chooses the largest numerical type used in the expression 
// (eg numType == double if the two expressions have leftHand::numType=int and leftHand::numType=double)
template<typename leftHand,typename rightHand>
struct largestType{
    using numType = typename IF<(sizeof(typename leftHand::numType) >= sizeof(typename  rightHand::numType)),
                   typename  leftHand::numType, typename rightHand::numType>::type;

};

template<typename Expr>
struct largestType<Expr,float>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(float)),
                   typename  Expr::numType, float>::type;
};

template<typename Expr>
struct largestType<float,Expr>{
    using numType = typename largestType<Expr,float>::numType;
};


template<typename Expr>
struct largestType<Expr,double>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(double)),
                   typename  Expr::numType, double>::type;
};

template<typename Expr>
struct largestType<double,Expr>{
    using numType = typename largestType<Expr,double>::numType;
};

template<typename Expr>
struct largestType<Expr,long double>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(long double)),
                   typename  Expr::numType, long double>::type;
};

template<typename Expr>
struct largestType<long double,Expr>{
    using numType = typename largestType<Expr,long double>::numType;
};

template<typename Expr>
struct largestType<Expr,int>{
    using numType = typename IF<(sizeof(typename Expr::numType) >= sizeof(int)),
                   typename  Expr::numType, int>::type;
};

template<typename Expr>
struct largestType<int,Expr>{
    using numType = typename largestType<Expr,int>::numType;
};

// template<typename leftHand,typename rightHand>
// struct largestType{
//     using numType = typename IF<(sizeof(leftHand) >= sizeof(rightHand)),
//                    leftHand, rightHand>::type;

// };


};

#endif