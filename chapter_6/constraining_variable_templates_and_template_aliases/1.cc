#include <iostream>

template <std::floating_point T>
constexpr T PI = T(3.1415926535897932385L);

int main(){
    std::cout << PI<double> << '\n';  // OK
    std::cout << PI<int> << '\n';     // error
    return 0;
}