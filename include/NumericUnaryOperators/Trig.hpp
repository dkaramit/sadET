#ifndef TrigOp_head
#define TrigOp_head
#include<cmath>

#include<misc.hpp>
#include<Numbers/Constant.hpp>
#include<NumericBinaryOperators/Addition.hpp>

namespace sadET{

/*------------------------Sin---------------------------------*/
template<typename Expr, typename dummy=void>
class Sin{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Sin(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::sin(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return cos(expr)*expr.derivative(ID) ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Sin &expr){os<<expr.evaluate();return os;} 

};

template<typename Expr>
inline auto sin(const Expr &expr){return Sin<Expr>(expr);}


template<typename Expr>
class Sin<Expr,typename enable_if<std::is_arithmetic<Expr>::value>::type>{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = Expr;
    
    Expr expr;

    Sin(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::sin(expr);}

    inline auto derivative(const unInt &ID)const{return Constant<Expr>(0) ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Sin &expr){os<<expr.evaluate();return os;} 

};

/*------------------------Cos---------------------------------*/
template<typename Expr, typename dummy=void>
class Cos{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Cos(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::cos(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return -sin(expr)*expr.derivative(ID) ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Cos &expr){os<<expr.evaluate();return os;} 

};

template<typename Expr>
inline auto cos(const Expr &expr){return Cos<Expr>(expr);}


template<typename Expr>
class Cos<Expr,typename enable_if<std::is_arithmetic<Expr>::value>::type>{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = Expr;
    
    Expr expr;

    Cos(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::cos(expr);}

    inline auto derivative(const unInt &ID)const{return Constant<Expr>(0);}
    
    friend std::ostream& operator<<(std::ostream& os, const Cos &expr){os<<expr.evaluate();return os;} 

};


}

#endif