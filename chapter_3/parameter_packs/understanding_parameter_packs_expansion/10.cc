#include <iostream>

template <typename... T>
int sum(T... args)
{
    return (... + args);
}

int main(){
    std::cout << sum() << '\n'; // error
    std::cout << sum(1) << '\n';
    std::cout << sum(1, 2) << '\n';
    std::cout << sum(1, 2, 3, 4, 5) << '\n';
    return 0;
}