#ifndef MISC_head
#define MISC_head

#include<type_traits>
#include<vector>
#include<map>
#include<string>


namespace sadET{

using IDType = std::size_t;
using std::enable_if;
using std::common_type;
using std::map;
using std::vector;
using std::string;
using std::to_string;


template<IDType ID, typename LD, typename dummy=void> class Variable;

// a concept to restric the types to sadET explression. This is useful to avoid operator overloading trying to use
// sadET overloads to regular objects. For example, if I overload operator+, I want the overload to work with 
// type "SadETExpression"
template<typename T> concept sadExpr = requires { typename std::decay_t<T>::is_sadET; };

// I may use this to do somehitng with only variables
template<typename T> concept variable  = requires { typename std::decay_t<T>::is_Var; };
// I may use this to do somehitng with only variables
template<typename T> concept constant = requires { typename std::decay_t<T>::is_Const; };

}

#endif