#include <type_traits>

template <typename ... Ts>
struct typelist {};

namespace detail
{
    template <typename TL>
    struct length;

    template <template <typename...> typename TL, typename... Ts>
    struct length<TL<Ts...>>
    {
        using type = std::integral_constant<std::size_t, sizeof...(Ts)>;
    };
}

template <typename TL>
using length_t = typename detail::length<TL>::type;

template <typename TL>
constexpr std::size_t length_v = length_t<TL>::value;

int main(){
    static_assert(length_t<typelist<int, double, char>>::value == 3);
    static_assert(length_v<typelist<int, double, char>> == 3);
    static_assert(length_v<typelist<int, double>> == 2);
    static_assert(length_v<typelist<int>> == 1);
    return 0;
}