#include <type_traits>

template <typename ... Ts>
struct typelist {};

struct empty_type {};

namespace detail
{
    template <std::size_t I, std::size_t N, typename TL>
    struct at_type;

    template <std::size_t I, std::size_t N, template <typename...> typename TL, typename T, typename... Ts>
    struct at_type<I, N, TL<T, Ts...>>
    {
        using type = std::conditional_t<I == N, T, typename at_type<I, N + 1, TL<Ts...>>::type>;
    };

    template <std::size_t I, std::size_t N>
    struct at_type<I, N, typelist<>>
    {
        using type = empty_type;
    };
}

template <std::size_t I, typename TL>
using at_t = typename detail::at_type<I, 0, TL>::type;

int main(){
    static_assert(std::is_same_v<at_t<0, typelist<>>, empty_type>);
    static_assert(std::is_same_v<at_t<0, typelist<int>>, int>);
    static_assert(std::is_same_v<at_t<0, typelist<int, char>>, int>);

    static_assert(std::is_same_v<at_t<1, typelist<>>, empty_type>);
    static_assert(std::is_same_v<at_t<1, typelist<int>>, empty_type>);
    static_assert(std::is_same_v<at_t<1, typelist<int, char>>, char>);

    static_assert(std::is_same_v<at_t<2, typelist<>>, empty_type>);
    static_assert(std::is_same_v<at_t<2, typelist<int>>, empty_type>);
    static_assert(std::is_same_v<at_t<2, typelist<int, char>>, empty_type>);
    return 0;
}
