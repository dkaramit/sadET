#ifndef NumUnOp_head
#define NumUnOp_head
#include<cmath>

#include<Constant.hpp>
#include<NumericBinaryOperators.hpp>

/*------------------------Negative---------------------------------*/
template<typename Expr>
class Neg{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Neg(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return -1*expr.evaluate();}

    inline auto derivative(const unInt &ID)const{return Constant<numType>(-1)*(expr.derivative(ID));}
    
    friend std::ostream& operator<<(std::ostream& os, const Neg &expr){os<<expr.evaluate();return os;} 

};

template<typename Expr>
auto operator-(const Expr &expr){return Neg<Expr>(expr);}



/*------------------------Exp---------------------------------*/
template<typename Expr>
class Exp{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Exp(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::exp(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return Exp<Expr>(expr)*(expr.derivative(ID));}
    friend std::ostream& operator<<(std::ostream& os, const Exp &expr){os<<expr.evaluate();return os;} 
};

template<typename Expr>
auto exp(const Expr &expr){return Exp<Expr>(expr);}

/*------------------------natural Log---------------------------------*/
template<typename Expr>
class Log{
    public:

    // again, this gives us the numerical type used in the expression
    using numType = typename Expr::numType;
    
    Expr expr;

    Log(const Expr &expr):expr(expr){}

    inline auto evaluate()const{return std::log(expr.evaluate());}

    inline auto derivative(const unInt &ID)const{return expr.derivative(ID)/expr ;}
    
    friend std::ostream& operator<<(std::ostream& os, const Log &expr){os<<expr.evaluate();return os;} 

};

template<typename Expr>
auto log(const Expr &expr){return Log<Expr>(expr);}


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
auto sin(const Expr &expr){return Sin<Expr>(expr);}

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
auto cos(const Expr &expr){return Cos<Expr>(expr);}


#endif