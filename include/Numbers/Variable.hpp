#ifndef Var_head
#define Var_head

#include<misc.hpp>

#include<Numbers/Constant.hpp>

namespace sadET{

// this is the varable class.
template<IDType ID, typename LD, typename dummy=void>
class Variable{

    public:
    //this will be used to propagate LD without needeless template arguments
    using numType = LD;

    Variable()=default;
    ~Variable()=default;

    IDType getID()const{return ID;}

    inline LD evaluate(const map<IDType,numType> &at)  const {
        if (at.find(this->getID()) == at.end()){throw std::runtime_error( std::string("No value for variable with ID: ") + std::to_string(this->getID()) ) ;}
        return at.at(this->getID());
    }

    constexpr auto derivative(const IDType &wrt) const { return wrt==this->getID() ? ONE<LD> :  ZERO<LD>; }

};




};

#endif
