#include <iostream>

template <typename T>
struct is_floating_point
{
    constexpr static bool value = false;
};

template <>
struct is_floating_point<float>
{
    constexpr static bool value = true;
};

template <>
struct is_floating_point<double>
{
    constexpr static bool value = true;
};

template <>
struct is_floating_point<long double>
{
    constexpr static bool value = true;
};

int main(){
    std::cout << is_floating_point<int>::value << '\n';
    std::cout << is_floating_point<float>::value << '\n';
    std::cout << is_floating_point<double>::value << '\n';
    std::cout << is_floating_point<long double>::value << '\n';
    std::cout << is_floating_point<std::string>::value << '\n';
    return 0;
}