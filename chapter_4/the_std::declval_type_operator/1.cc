#include <utility>

template <typename T, typename U>
struct composition
{
    using result_type = decltype(T{} + U{});
};

int main(){

    static_assert( std::is_same_v<double, composition<int, double>::result_type>) ;
    return 0;
}