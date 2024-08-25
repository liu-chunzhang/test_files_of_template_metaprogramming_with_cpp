#include <iostream>
#include <type_traits>

template<typename T, typename... Ts>
inline constexpr bool are_same_v = std::conjunction_v<std::is_same<T, Ts>...>;

template <typename ... T>
concept HomogenousRange = requires(T... t)
{
    (... + t);
    requires are_same_v<T...>;
    requires sizeof...(T) > 1;
};

template <typename ... T>
requires HomogenousRange<T...>
auto add(T&&... t)
{
    return (... + t);
}

int main(){
    std::cout << add( 1 , 2 ) << '\n' ;     // OK
    std::cout << add( 1 , 2.0 ) << '\n' ;   // error, types not the same
    std::cout << add( 1 ) << '\n' ;         // error, size not greater than 1

    static_assert(HomogenousRange<int, int>);
    static_assert(!HomogenousRange<int>);
    static_assert(!HomogenousRange<int, double>);
    return 0;
}