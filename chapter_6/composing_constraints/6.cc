#include <type_traits>

template <typename ... T>
requires (std::is_integral_v<T> && ...)
auto add(T ... args)
{
    return (args + ...);
}

int main(){
    add(1, 2, 3);
    add(1, 42.0);
    return 0;
}