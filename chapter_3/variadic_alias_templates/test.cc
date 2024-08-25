#include <iostream>
#include <tuple>

template<typename T, T... Ints>
struct integer_sequence
{
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<typename T, std::size_t N, T... Is>
struct make_integer_sequence : make_integer_sequence<T, N - 1, Is...> {};

template<typename T, T... Is>
struct make_integer_sequence<T, 0, Is...> : integer_sequence<T, Is...> {};

template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;

template<typename... T>
using index_sequence_for = make_index_sequence<sizeof...(T)>;

template<typename Tuple, std::size_t... Ints>
auto select_tuple(Tuple&& tuple, index_sequence<Ints...>)
{
    return std::make_tuple(
        std::get<Ints>(std::forward<Tuple>(tuple))...);
}

int main(){
    std::tuple<int, char, double> t1{ 42, 'x', 42.99 };
    auto t2 = select_tuple(t1, index_sequence<0, 2>{});
    std::cout << get<0>(t2)  ;
    return 0;
}