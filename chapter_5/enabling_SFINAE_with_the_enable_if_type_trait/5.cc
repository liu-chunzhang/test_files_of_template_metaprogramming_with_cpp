#include <iostream>
#include <type_traits>

template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
struct integral_wrapper
{
    T value;

    integral_wrapper(T v) : value(v) {}
};

template <typename T, typename = typename std::enable_if_t<std::is_floating_point_v<T>>>
struct floating_wrapper
{
    T value;

    floating_wrapper(T v) : value(v) {}
};

int main(){
    integral_wrapper w1{ 42 };   // OK
    floating_wrapper w5{ 42.0 }; // OK
    return 0;
}