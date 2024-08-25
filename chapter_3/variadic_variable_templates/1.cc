#include <iostream>

template <int... R>
constexpr int Sum = (... + R);

int main(){
    std::cout << Sum<1> << '\n';
    std::cout << Sum<1, 2> << '\n';
    std::cout << Sum<1, 2, 3, 4, 5> << '\n';
    return 0;
}