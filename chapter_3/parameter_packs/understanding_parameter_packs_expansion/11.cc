#include <array>

template <typename... T>
auto make_array(T... args)
{
    return std::array<std::common_type_t<T...>, sizeof...(T)> {args...};
};

int main(){
    auto arr = make_array( 1 , 2 , 3 , 4 ) ;
    return 0;
}