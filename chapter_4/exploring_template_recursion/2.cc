#include <iostream>

template <unsigned int N>
inline constexpr unsigned int factorial = N * factorial<N - 1>;

template <>
inline constexpr unsigned int factorial<0> = 1;

int main() {
    std::cout << factorial<4>::value << '\n' ;
    return 0 ;
}