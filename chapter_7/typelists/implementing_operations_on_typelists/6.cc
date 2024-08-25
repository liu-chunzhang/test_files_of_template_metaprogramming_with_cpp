#include <type_traits>

template <typename ... Ts>
struct typelist {};

namespace detail
{
    template <typename TL>
    struct pop_front_type;

    template <template <typename...> typename TL, typename T, typename... Ts>
    struct pop_front_type<TL<T, Ts...>>
    {
        using type = TL<Ts...>;
    };

    template <template <typename...> typename TL>
    struct pop_front_type<TL<>>
    {
        using type = TL<>;
    };
}

template <typename TL>
using pop_front_t = typename detail::pop_front_type<TL>::type;

int main(){
    static_assert(std::is_same_v<pop_front_t<typelist<>>, typelist<>>);
    static_assert(std::is_same_v<pop_front_t<typelist<char>>, typelist<>>);
    static_assert(std::is_same_v<pop_front_t<typelist<double, char>>, typelist<char>>);
    return 0;
}