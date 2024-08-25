#include <iostream>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept Signed = std::is_signed_v<T>;

template <typename T>
concept SignedIntegral = Integral<T> && Signed<T>;

template <SignedIntegral T>
T decrement(T value)
{
    return --value;
}

int main(){
    int a = 3 ;
    std::cout << "decrement( a ) = " << decrement( a ) << '\n' ;
    std::cout << "a = " << a << '\n' ;
    return 0;
}