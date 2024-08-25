#include <type_traits>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename ... T>
requires (Integral<T> && ...)
auto add(T ... args)
{
    return (args + ...);
}

int main(){
    add(1, 2, 3);
    add(1, 42.0);
    return 0;
}