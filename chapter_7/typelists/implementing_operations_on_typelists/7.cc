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

    template <std::ptrdiff_t N, typename R, typename TL>
    struct pop_back_type;
    
    template <std::ptrdiff_t N, typename... Ts, typename U, typename... Us>
    struct pop_back_type<N, typelist<Ts...>, typelist<U, Us...>> 
    { 
        using type = typename pop_back_type<N - 1, typelist<Ts..., U>, typelist<Us...>>::type;
    };

    template <typename... Ts, typename... Us>
    struct pop_back_type<0, typelist<Ts...>, typelist<Us...>>
    { 
        using type = typelist<Ts...>;
    };

    template <typename... Ts, typename U, typename... Us>
    struct pop_back_type<0, typelist<Ts...>, typelist<U, Us...>>
    { 
        using type = typelist<Ts...>;
    };

    template <>
    struct pop_back_type<-1, typelist<>, typelist<>>
    {
        using type = typelist<>;
    };
}

template <typename TL>
using length_t = typename detail::length<TL>::type;

template <typename TL>
constexpr std::size_t length_v = length_t<TL>::value;

template <typename TL>
using pop_back_t = typename detail::pop_back_type<static_cast<std::ptrdiff_t>(length_v<TL>)-1, typelist<>, TL>::type;

int main(){
    static_assert(std::is_same_v<pop_back_t<typelist<>>, typelist<>>);
    static_assert(std::is_same_v<pop_back_t<typelist<double>>, typelist<>>);
    static_assert(std::is_same_v<pop_back_t<typelist<double, char>>, typelist<double>>);
    static_assert(std::is_same_v<pop_back_t<typelist<double, char, int>>, typelist<double, char>>);
    return 0;
}
