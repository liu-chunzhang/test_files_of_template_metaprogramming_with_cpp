#include <iostream>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
T add(T a, T b)
{
    std::cout << "requires Integral<T> T add(T a, T b)\n" ;
    return a + b;
}

template <Integral T>
requires (sizeof(T) == 4)
T add(T a, T b)
{   
    std::cout << "requires (sizeof(T) == 4) T add(T a, T b)\n" ;
    return a + b;
}

int main(){
    add( (short)1 , (short)2 );
    add(1, 2);
    return 0;
}