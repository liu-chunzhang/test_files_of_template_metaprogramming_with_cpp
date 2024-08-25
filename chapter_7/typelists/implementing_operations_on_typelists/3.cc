#include <type_traits>

template <typename ... Ts>
struct typelist {};

struct empty_type {};

namespace detail
{
    template <typename TL>
    struct back_type;

    template <template <typename...> typename TL, typename T, typename... Ts>
    struct back_type<TL<T, Ts...>>
    {
        using type = back_type<TL<Ts...>>::type;
    };

    template <template <typename...> typename TL, typename T>
    struct back_type<TL<T>>
    {
        using type = T;
    };

    template <template <typename...> typename TL>
    struct back_type<TL<>>
    {
        using type = empty_type;
    };
}

template <typename TL>
using back_t = typename detail::back_type<TL>::type;

int main(){
    static_assert(std::is_same_v<back_t<typelist<>>, empty_type>);
    static_assert(std::is_same_v<back_t<typelist<int>>, int>);
    static_assert(std::is_same_v<back_t<typelist<int, double, char>>, char>);
    return 0;
}