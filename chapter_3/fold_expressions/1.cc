#include <iostream>

template <typename... T>
int sum(T... args)
{
    return (... + args);
}

template <typename... T>
int sum_from_zero(T... args)
{
    return (0 + ... + args);
}

int main(){
    std::cout << sum() << '\n'; // error
    std::cout << sum(1) << '\n';
    std::cout << sum(1, 2) << '\n';
    std::cout << sum(1, 2, 3, 4, 5) << '\n';

    std::cout << sum_from_zero() << '\n';
    std::cout << sum_from_zero(1, 2, 3) << '\n';
    return 0;
}