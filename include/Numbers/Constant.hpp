#ifndef Const_head
#define Const_head
#include<misc.hpp>

namespace sadET{

template<typename LD,typename dummy=void> class Constant;

template<typename LD> static Constant<LD> ZERO(0);
template<typename LD> static Constant<LD> ONE(1);

template<typename LD, typename dummy>
class Constant{

    const LD value;
    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;
    
    Constant()=delete;
    ~Constant()=default;
    Constant(const LD &x):value(x){}
    
    
    inline LD evaluate(const map<IDType,numType> &at)  const {return value;}
    constexpr auto derivative(const IDType &ID)  const {return ZERO<LD>;}
};


};
#endif
