#include <utility>
#include <vector>

template <typename T, typename... Ts, typename Allocator = std::allocator<T>>
auto make_vector(T&& first, Ts&&... args)
{
    return std::vector<std::decay_t<T>, Allocator> { std::forward<T>(first), std::forward<Ts>(args)... };
}

template <typename T>
struct wrapper
{
    T data;
};

template <typename T>
constexpr wrapper<T> make_wrapper(T&& data)
{
    return wrapper{ data };
}

template <typename T>
wrapper(T) -> wrapper<T>;

int main() {

    std::pair   p{ 42, 42.0 };      // std::pair<int,double>
    std::vector v{ 1,2,3,4,5 };     // std::vector<int>
    wrapper     w{ 42 };            // wrapper<int>
    return 0 ;
}
