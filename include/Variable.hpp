#ifndef Var_head
#define Var_head
#include<iostream>
#include<Constant.hpp>

namespace sadET{


// __EQ and __VAL are used to determine the type that the derivative returns;
// ie Zero when ID!=requestID and positiveUn otherwise. 
template<unInt T1, unInt T2>
struct __EQ{
    constexpr static unInt check= (T1==T2);  
};
 
 
template<typename LD, unInt check>
struct __VAL{
    
    using result = Zero<LD>   ;  
};



template<typename LD>
struct __VAL<LD,1>{
    using result =  positiveUn<LD>   ;  
};

// this is the varable class.
template<typename LD, unInt ID>
class Variable{
    LD value;
    public:


    //this will be used to propagate LD without needeless template arguments
    using numType = LD;
    
    Variable()=default;
    Variable(const LD &x):value(x){}


    inline LD evaluate()  const {return value;}
    inline LD& evaluate()  {return value;}


    template<unInt requestID> 
    auto derivative() const {
        typename __VAL< LD, __EQ<ID,requestID>::check >::result tmp;
        return tmp;
    };         

    friend std::ostream& operator<<(std::ostream& os, const Variable &expr){os<<expr.evaluate();return os;} 

};




};

#endif
