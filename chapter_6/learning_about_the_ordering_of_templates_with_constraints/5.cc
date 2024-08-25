#include <iostream>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
    requires Integral<T>
T add(T a, T b)
{
    std::cout << "requires Integral<T> T add(T a, T b)\n" ;
    return a + b;
}

template <typename T>
    requires Integral<T> && (sizeof(T) == 4)
T add(T a, T b)
{
    std::cout << "requires Integral<T> && (sizeof(T) == 4) T add(T a, T b)\n" ;
    return a + b;
}

int main(){
    add( (short)1 , (short)2 );
    add(1, 2);
    return 0;
}