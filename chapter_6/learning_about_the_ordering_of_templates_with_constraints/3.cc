#include <iostream>

template <typename T>
    requires (sizeof(T) == 4)
T add(T a, T b)
{
    std::cout << "requires (sizeof(T) == 4) T add(T a, T b)\n" ;
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
    add( (short)1 , (short)2 );
    add(1, 2);
    return 0;
}