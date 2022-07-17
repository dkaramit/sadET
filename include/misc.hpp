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


}

#endif