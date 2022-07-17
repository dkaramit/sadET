#ifndef MISC_head
#define MISC_head

#include<type_traits>
#include<vector>
#include<map>


namespace sadET{

using IDType = std::size_t;
using std::common_type;
using std::map;
using std::vector;

template<IDType ID, typename LD, typename dummy=void> class Variable;


};

#endif