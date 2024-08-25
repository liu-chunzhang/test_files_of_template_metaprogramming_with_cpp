#include <iostream>

template <unsigned int n>
constexpr unsigned int factorial()
{
    if constexpr (n > 1)
        return n * factorial<n - 1>();
    else
        return 1;
}

int main(){
    std::cout << factorial<1>() << '\n';
    std::cout << factorial<2>() << '\n';
    std::cout << factorial<3>() << '\n';
    std::cout << factorial<4>() << '\n';
    std::cout << factorial<5>() << '\n';
    return 0;
}