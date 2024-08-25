#include <iostream>
#include <type_traits>

template<class T> 
constexpr bool always_false = std::false_type::value;

template <typename T>
std::string as_string(T&& value)
{
    using value_type = std::decay_t<T>;

    if constexpr (std::is_null_pointer_v<value_type>)
        return "null";
    else if constexpr (std::is_same_v<value_type, bool>)
        return value ? "true" : "false";
    else if constexpr (std::is_arithmetic_v<value_type>)
        return std::to_string(value);
    else
        static_assert(always_false<T>);
}

int main(){
    std::cout << as_string( true ) << '\n' ;    // OK
    std::cout << as_string( 42 ) << '\n' ;      // OK

    bool f = true;
    std::cout << as_string(f) << '\n';          // error

    int n = 42;
    std::cout << as_string(n) << '\n';          // error
    return 0;
}