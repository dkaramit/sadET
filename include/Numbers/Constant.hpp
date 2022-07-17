#ifndef Const_head
#define Const_head

#include<misc.hpp>

namespace sadET{

template<typename LD>
struct templateP{
    static_assert(std::is_arithmetic<LD>::value,"Only numbers");
    using numType = LD;
    constexpr templateP()=delete;
    ~templateP()=default;
    
    constexpr templateP(LD value):value(value){}
    
    const LD value;
};

template<typename LD, templateP<LD> Value>
class Constant;

template<typename LD> constexpr static Constant<LD,0> ZERO;
template<typename LD> constexpr static Constant<LD,1> ONE;

// this is the varable class.
template<typename LD, templateP<LD> Value>
class Constant{

    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;

    Constant()=default;
    ~Constant()=default;


    template<typename T>
    inline numType evaluate(const map<IDType,T> &at)  const { return value; }

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const { return ZERO<numType> ;}

    string str()const{return to_string(value);}


    constexpr static numType value=Value.value;
};



template<typename Expr> struct isConst{constexpr static bool value=false;};

template<typename LD, templateP<LD> Value>
struct isConst<Constant<LD,Value>>{constexpr static bool value=true;};




}

#endif