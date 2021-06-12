#ifndef Const_head
#define Const_head

namespace sadET{

template<typename LD, typename dummy=void>
class Constant{

    LD value;
    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;
    
    Constant()=default;
    Constant(const LD &x):value(x){}
    inline LD evaluate()  const {return value;}
    inline LD& evaluate()  {return value;}
    inline auto derivative(const unInt &ID)  const {return Constant<LD>(0);}

    friend std::ostream& operator<<(std::ostream& os, const Constant &expr){os<<expr.evaluate();return os;} 

};

};
#endif
