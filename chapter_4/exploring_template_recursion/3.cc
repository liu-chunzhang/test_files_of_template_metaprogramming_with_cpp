#include <iostream>

template <unsigned int n>
constexpr unsigned int factorial()
{
    return n * factorial<n - 1>();
}

template<> constexpr unsigned int factorial<1>() { return 1; }
template<> constexpr unsigned int factorial<0>() { return 1; }

int main() {
    std::cout << factorial<4>() << '\n' ;
    return 0 ;
}