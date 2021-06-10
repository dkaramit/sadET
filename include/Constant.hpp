#ifndef Const_head
#define Const_head

namespace sadET{

// use specific constants (0 and \pm 1), which may be used to 
// simplify the results of operators based on the types.
// For example Addition<Zero,Variable> --> Variable.
// I will not do it now, but I want to have the option
template<typename LD>
class Zero{

    public:
    using numType = LD;
    
    Zero()=default;
    inline LD evaluate()  const {return 0;}

    template<unInt requestID>
    inline Zero derivative()  const {return Zero();}

    friend std::ostream& operator<<(std::ostream& os, const Zero &expr){os<<expr.evaluate();return os;} 

};

template<typename LD>
class positiveUn{

    public:
    using numType = LD;
    
    positiveUn()=default;
    inline LD evaluate()  const {return 1;}

    template<unInt requestID>
    inline auto derivative()  const {return Zero<LD>();}

    friend std::ostream& operator<<(std::ostream& os, const positiveUn &expr){os<<expr.evaluate();return os;} 

};

template<typename LD>
class negativeUn{

    public:
    using numType = LD;
    
    negativeUn()=default;
    inline LD evaluate()  const {return -1;}

    template<unInt requestID>
    inline auto derivative()  const {return Zero<LD>();}

    friend std::ostream& operator<<(std::ostream& os, const negativeUn &expr){os<<expr.evaluate();return os;} 

};



template<typename LD>
class Constant{

    LD value;
    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;
    
    Constant()=default;
    Constant(const LD &x):value(x){}
    inline LD evaluate()  const {return value;}
    inline LD& evaluate()  {return value;}

    template<unInt requestID> 
    inline auto derivative()  const {return Constant<LD>(0);}

    friend std::ostream& operator<<(std::ostream& os, const Constant &expr){os<<expr.evaluate();return os;} 

};

};
#endif
