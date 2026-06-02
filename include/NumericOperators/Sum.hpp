#ifndef Sum_head
#define Sum_head
#include<iostream>
#include<cmath>
#include<tuple>

#include<misc.hpp>
#include<NumericUnaryOperators/Negative.hpp>


namespace sadET{

template<typename... Terms>
class Sum{
    public:
        //this tells me that this is a sadET expression
        using is_sadET = void;
        // the sum will be represented as a list of terms
        std::tuple<Terms...> terms;
        using numType = std::common_type_t<typename Terms::numType...>;
        
        constexpr Sum(const Terms&... terms):terms(terms...){}

        template<typename T>
        inline auto evaluate(const map<IDType, T>& at) const {
            //-----------------about std::apply-----------------
            // say I have a tuple t={x,y,z,u} and a function f, then
            // std::apply( f , t ) = f(x,y,z,u) 
            //-----------------about the lambda-----------------
            // [&](const auto& ... term) = function that takes any number of parameters
            // term.evaluate(at) + ... -> this defines the pattern "1st argument + 2nd argumen + 3rd argument ..."
            // basically this is the same as double f(const double& ...x){ return (x + ...); }, but with arbitrary types.
            return std::apply( [&](const auto& ... term) { return (term.evaluate(at) + ...); }, terms );
        }

        template<IDType WRT,typename T>
        constexpr auto derivative(const Variable<WRT,T> &wrt) const {
            // std::decay_t just removes any const, &, &&, or anything that is not the actual type of term.derivative(wrt).
            return std::apply( [&](const auto& ... term) { return  Sum<std::decay_t <decltype(term.derivative(wrt))> ...>(term.derivative(wrt)...); }, terms );
            // this does the same thing
            // return std::apply( [&](const auto& ... term) { return  make_sum(term.derivative(wrt)...); }, terms );
        }



        string str() const {
            return string("(+") + str_expr() + string(")"); 
        }
    
    private:
        string str_expr() const {
            return std::apply([&](const auto& first, const auto&... rest) { return first.str() + ((string(",") + rest.str()) + ...); },terms);
        }
    
};

// construct the sum instead of calling the constructor
template<sadExpr... Terms> constexpr auto make_sum(const Terms&... terms) { return Sum<Terms...>(terms...); }

// ----------------------------------operator+ overloading------------------------------
// start with two terms 
template<sadExpr L, sadExpr R>
constexpr inline auto operator+(const L& lhs, const R& rhs) { return make_sum(lhs, rhs);}

// special case: Sum + expr
template<sadExpr... L, sadExpr R>
constexpr inline auto operator+(const Sum<L...>& lhs, const R& rhs) {  
    return std::apply( [&](const auto& ... term) { return  make_sum(term...,rhs); }, lhs.terms ); 
}

// special case: expr + Sum 
template<sadExpr L, sadExpr... R>
constexpr inline auto operator+(const L& lhs, const Sum<R...>& rhs) {  
    return std::apply( [&](const auto& ... term) { return  make_sum(lhs, term...); }, rhs.terms ); 
}

// special case: Sum + Sum 
template<sadExpr... Ls, sadExpr... Rs>
constexpr inline auto operator+(const Sum<Ls...>& lhs, const Sum<Rs...>& rhs) {
    return std::apply( [&](const auto& ... term) { return  make_sum(term...); }, std::tuple_cat(lhs.terms,rhs.terms) ); 
}


// ----------------------------------operator- overloading------------------------------
template<sadExpr L, sadExpr R>
constexpr inline auto operator-(const L& lhs, const R& rhs) {
    return make_sum(lhs, -rhs);
}

// special case: Sum - expr
template<sadExpr... L, sadExpr R>
constexpr inline auto operator-(const Sum<L...>& lhs, const R& rhs) {  
    return std::apply( [&](const auto& ... term) { return  make_sum(term...,-rhs); }, lhs.terms ); 
}

// special case: expr - Sum 
template<sadExpr L, sadExpr... R>
constexpr inline auto operator-(const L& lhs, const Sum<R...>& rhs) {  
    return std::apply( [&](const auto& ... term) { return  make_sum(lhs, -term...); }, rhs.terms ); 
}

// special case: Sum - Sum 
template<sadExpr... Ls, sadExpr... Rs>
constexpr inline auto operator-(const Sum<Ls...>& lhs, const Sum<Rs...>& rhs) {
    return std::apply( [&](const auto& ... term) { return  make_sum(-term...); }, std::tuple_cat(lhs.terms,rhs.terms) ); 
}

}

#endif
