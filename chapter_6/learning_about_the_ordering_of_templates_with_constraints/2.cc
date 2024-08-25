#include <iostream>

template <typename T>
T add(T a, T b)
{
    std::cout << "T add(T a, T b)\n" ;
    return a + b;
}

template <typename T>
requires std::is_integral_v<T>
T add(T a, T b)
{
    std::cout << "requires std::is_integral_v<T> T add(T a, T b)\n" ;
    return a + b;
}

int main(){
    add(1.0, 2.0);
    add(1, 2);
    return 0;
}