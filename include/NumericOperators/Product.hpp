#ifndef Prod_head
#define Prod_head
#include<iostream>
#include<cmath>

#include<tuple>

#include<misc.hpp>
#include<NumericOperators/Sum.hpp>



namespace sadET{

template<typename... Factors>
class Product{
    public:
        //this tells me that this is a sadET expression
        using is_sadET = void;
        // the product will be represented as a list of factors
        std::tuple<Factors...> factors;
        using numType = std::common_type_t<typename Factors::numType...>;
        
        constexpr Product(const Factors&... factors):factors(factors...){}

        template<typename T>
        inline auto evaluate(const map<IDType, T>& at) const {
            return std::apply( [&](const auto& ... factor) { return (factor.evaluate(at) * ...); }, factors );
        }

        // For the derivative, we need to construct a tuple where in the Ith element we substitute Ith factor with its derivative.
        // This takes some effort at compile time. 
        // We need several functions, whihc I put in provate.
        template<IDType WRT, typename T>
        constexpr auto derivative(const Variable<WRT, T>& wrt) const {
            return derivative_impl<WRT, T>(wrt, std::make_index_sequence<sizeof...(Factors)>{});
        }

        string str() const {
            return string("(*") + str_expr() + string(")"); 
        }

    private: 
        //this is the actual implementation of the derivative. It makes a sum from the tume that contains
        // sizeof...(Factors) number of elements, where in its Ith element the  Ith factor is replcaced with its derivative.
        template<IDType WRT, typename T, std::size_t... Is>
        constexpr auto derivative_impl(const Variable<WRT, T>& wrt,std::index_sequence<Is...>) const {
            return make_sum(derivative_product_term<WRT, T, Is>( wrt,std::make_index_sequence<sizeof...(Factors)>{})...);
        }

        // this retuns the Ith term in the sum I want for derivative_impl. 
        // It is a product of all factors, but the Ith factor is replaced with its derivative 
        template<IDType WRT, typename T, std::size_t I, std::size_t... Js>
        constexpr auto derivative_product_term(const Variable<WRT, T>& wrt,std::index_sequence<Js...>) const {
            return make_product(factor_or_derivative<WRT, T, I, Js>(wrt)...);
        }

        //This returns the factor if J!=I or its derivative if J==I.
        template<IDType WRT, typename T, std::size_t I, std::size_t J>
        constexpr auto factor_or_derivative(const Variable<WRT, T>& wrt) const {
            const auto& factor = std::get<J>(factors);

            if constexpr (I == J) {
                return factor.derivative(wrt);
            } else {
                return factor;
            }
        }

        string str_expr() const {
            return std::apply([&](const auto& first, const auto&... rest) { return first.str() + ((string(",") + rest.str()) + ...); },factors);
        }

};

// construct the sum instead of calling the constructor
template<sadExpr... Factors> constexpr auto make_product(const Factors&... factors) { return Product<Factors...>(factors...); }

// ----------------------------------operator* overloading------------------------------
// start with two factors 
template<sadExpr L, sadExpr R>
constexpr inline auto operator*(const L& lhs, const R& rhs) { return make_product(lhs, rhs);}

// special case: Product * expr
template<sadExpr... L, sadExpr R>
constexpr inline auto operator*(const Product<L...>& lhs, const R& rhs) {  
    return std::apply( [&](const auto& ... factor) { return  make_product(factor...,rhs); }, lhs.factors ); 
}

// special case: expr * Product 
template<sadExpr L, sadExpr... R>
constexpr inline auto operator*(const L& lhs, const Product<R...>& rhs) {  
    return std::apply( [&](const auto& ... factor) { return  make_product(lhs, factor...); }, rhs.factors ); 
}

// special case: Product + Product 
template<sadExpr... Ls, sadExpr... Rs>
constexpr inline auto operator*(const Product<Ls...>& lhs, const Product<Rs...>& rhs) {
    return std::apply( [&](const auto& ... factor) { return  make_product(factor...); }, std::tuple_cat(lhs.factors,rhs.factors) ); 
}



}

#endif
