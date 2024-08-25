#include <type_traits>

template <typename ... Ts>
struct typelist {};

namespace detail
{
    template <typename TL, typename T>
    struct push_back_type;

    template <template <typename...> typename TL, typename T, typename... Ts>
    struct push_back_type<TL<Ts...>, T>
    {
        using type = TL<Ts..., T>;
    };

    template <typename TL, typename T>
    struct push_front_type;

    template <template <typename...> typename TL, typename T, typename... Ts>
    struct push_front_type<TL<Ts...>, T>
    {
        using type = TL<T, Ts...>;
    };
}

template <typename TL, typename T>
using push_back_t = typename detail::push_back_type<TL, T>::type;

template <typename TL, typename T>
using push_front_t = typename detail::push_front_type<TL, T>::type;

int main(){
    static_assert(std::is_same_v<push_back_t<typelist<>, int>, typelist<int>>);
    static_assert(std::is_same_v<push_back_t<typelist<char>, int>, typelist<char, int>>);
    static_assert(std::is_same_v<push_back_t<typelist<double, char>, int>, typelist<double, char, int>>);

    static_assert(std::is_same_v<push_front_t<typelist<>, int>, typelist<int>>);
    static_assert(std::is_same_v<push_front_t<typelist<char>, int>, typelist<int, char>>);
    static_assert(std::is_same_v<push_front_t<typelist<double, char>, int>, typelist<int, double, char>>);
    return 0;
}

