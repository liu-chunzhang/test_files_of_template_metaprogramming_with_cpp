#include <iostream>
#include <type_traits>

template<class T> 
constexpr bool always_false = std::false_type::value;

template <typename T>
std::string as_string(T value)
{
    if constexpr (std::is_null_pointer_v<T>)
        return "null";
    else if constexpr (std::is_same_v<T, bool>)
        return value ? "true" : "false";
    else if constexpr (std::is_arithmetic_v<T>)
        return std::to_string(value);
    else
        static_assert(always_false<T>);
}

int main(){
    std::cout << as_string( true ) << '\n' ;    // prints true
    std::cout << as_string( false ) << '\n' ;   // prints false
    return 0;
}