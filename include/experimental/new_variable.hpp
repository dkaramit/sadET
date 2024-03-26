#include<Numbers/Variable.hpp>
#include<misc.hpp>

namespace sadET{

    template<IDType> struct Flag {  friend constexpr bool flag(Flag); };

    template<IDType N>
    struct Writer {
    friend constexpr bool flag(Flag<N>) { 
        return true; 
    }
    static constexpr IDType value = N;
    };


    template<IDType N = 0>
    constexpr IDType reader(float) {
    return Writer<N>::value;
    }


    template<auto T = []{}>
    constexpr auto unique() {
    return T;
    }

    template<IDType N = 0,
            bool = flag(Flag<N>{}),
            auto = unique()>
    constexpr IDType reader(IDType) {
    return reader<N + 1>(IDType{});
    }

    template<IDType R = reader<0>(IDType{})>
    constexpr IDType next() {
    return R;
    }

    template<typename LD, IDType ID=next()>
    inline constexpr auto new_variable(){ return Variable<ID,LD>(); }


}
