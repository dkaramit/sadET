#ifndef NumBinOp_head
#define NumBinOp_head
#include<cmath>

/*------------------------Addition---------------------------------*/
template<typename leftHand, typename rightHand>
class Addition{
    public:

    leftHand LH;
    rightHand RH;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate () {return LH.evaluate() + RH.evaluate();}

    inline auto derivative(){return LH.derivative() + RH.derivative();}
};

template<typename leftHand, typename rightHand>
auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH);}


/*------------------------Multiplication---------------------------------*/
template<typename leftHand, typename rightHand>
class Multiplication{
    public:

    leftHand LH;
    rightHand RH;

    Multiplication(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    inline auto evaluate () {return LH.evaluate() * RH.evaluate();}

    inline auto derivative(){return LH.derivative()*RH + RH.derivative()*LH;}
};

template<typename leftHand, typename rightHand>
auto operator*(const leftHand &LH, const rightHand &RH){return Multiplication<leftHand,rightHand>(LH,RH);}


#endif