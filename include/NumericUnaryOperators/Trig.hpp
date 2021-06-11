#ifndef TrigOp_head
#define TrigOp_head
#include<cmath>


namespace sadET{

/*------------------------Sin---------------------------------*/
template<typename Expr>
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

/*------------------------Cos---------------------------------*/
template<typename Expr>
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


}

#endif