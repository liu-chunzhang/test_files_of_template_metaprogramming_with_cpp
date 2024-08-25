#include <iostream>
#include <tuple>

template<typename T, T... Ints>
struct integer_sequence
{
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<typename Tuple, std::size_t... Ints>
auto select_tuple(Tuple&& tuple, index_sequence<Ints...>)
{
    return std::make_tuple(
        std::get<Ints>(std::forward<Tuple>(tuple))...);
}

int main(){
    std::tuple<int, char, double> t1{ 42, 'x', 42.99 };
    auto t2 = select_tuple(t1, index_sequence<0, 2>{});
    std::cout << get<0>( t2 ) << '\t' << get<1>( t2 ) << std::endl;
    return 0;
}