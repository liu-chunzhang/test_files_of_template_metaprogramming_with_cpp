#include <type_traits>

template <typename ... Ts>
struct typelist {};

template <typename ... Ts>
struct transformer
{
    using input_types = typelist<Ts...>;
    using output_types = typelist<std::add_const_t<Ts>...>;
};

int main(){
    static_assert( std::is_same_v<transformer<int, double>::output_types, typelist<int const, double const>>);
    return 0;
}
