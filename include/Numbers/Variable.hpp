#ifndef Var_head
#define Var_head

#include<misc.hpp>
#include<Numbers/Constant.hpp>

namespace sadET{

// this is the varable class.
template<IDType ID, typename LD, typename dummy>
class Variable{
    static_assert(std::is_floating_point<LD>::value, "Use only floating point numbers!");

    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;

    Variable()=default;
    ~Variable()=default;

    IDType getID()const{return ID;}

    template<typename T>
    inline typename std::common_type<T,numType>::type  evaluate(const map<IDType,T> &at)  const {
        if (at.find(this->getID()) == at.end()){throw std::runtime_error( std::string("No value for variable with ID: ") + std::to_string(this->getID()) ) ;}
        return at.at(this->getID());
    }

    template<IDType WRT,typename T>
    constexpr auto derivative(const Variable<WRT,T> &wrt) const {
        if constexpr(WRT==ID) return ONE<numType>;
        else return ZERO<numType>;
    }

};

};

#endif
