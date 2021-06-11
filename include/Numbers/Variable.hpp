#ifndef Var_head
#define Var_head

#include<Numbers/Constant.hpp>

namespace sadET{

// this is the varable class.
template<typename LD>
class Variable{
    LD value;

    unInt ID; //at some point I am going to use an numeric value in order to get the derivatives wrt multiple variables
    public:


    //this will be used to propagate LD without needeless template arguments
    using numType = LD;

    // inline static unInt numberOfVariables=0; //number of variables created. It is used for id's
    // Variable(const LD &x):value(x),ID(numberOfVariables++){}
    
    Variable()=default;
    Variable(const LD &x, const unInt &ID):value(x),ID(ID){}

    unInt getID()const{return ID;}
    unInt& getID(){return ID;}

    inline LD evaluate()  const {return value;}
    inline LD& evaluate()  {return value;}

    inline auto derivative(const unInt &ID) const {
        if (ID==this->ID){return Constant<LD>(1);}
        else{return Constant<LD>(0);}
         
         
    }

    friend std::ostream& operator<<(std::ostream& os, const Variable &expr){os<<expr.evaluate();return os;} 

};

};

#endif
