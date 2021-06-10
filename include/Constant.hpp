#ifndef Const_head
#define Const_head


template<typename LD>
class Constant{

    LD value;
    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;
    
    Constant(const LD &x):value(x){}
    LD evaluate()  const {return value;}
    auto derivative(const unInt &ID)  const {return Constant<LD>(0);}

    friend std::ostream& operator<<(std::ostream& os, const Constant &expr){os<<expr.evaluate();return os;} 

};

#endif
