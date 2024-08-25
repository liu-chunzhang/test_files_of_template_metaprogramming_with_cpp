#include <type_traits>

template <typename ... Ts>
struct typelist {};

struct empty_type {};

namespace detail
{
    template <typename TL>
    struct front_type;

    template <template <typename...> typename TL, typename T, typename... Ts>
    struct front_type<TL<T, Ts...>>
    {
        using type = T;
    };

    template <template <typename...> typename TL>
    struct front_type<TL<>>
    {
        using type = empty_type;
    };
}

template <typename TL>
using front_t = typename detail::front_type<TL>::type;

int main(){
    static_assert(std::is_same_v<front_t<typelist<>>, empty_type>);
    static_assert(std::is_same_v<front_t<typelist<int>>, int>);
    static_assert(std::is_same_v<front_t<typelist<int, double, char>>, int>);
    return 0;
}