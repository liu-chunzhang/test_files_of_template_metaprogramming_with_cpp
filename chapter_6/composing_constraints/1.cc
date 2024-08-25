#include <iostream>

using namespace std::string_literals;

template <typename T>
requires std::is_integral_v<T> && std::is_signed_v<T>
T decrement(T value) 
{
    return --value ;
}

int main(){
    int a = 3 ;
    std::cout << "decrement( a ) = " << decrement( a ) << '\n' ;
    std::cout << "a = " << a << '\n' ;
    return 0;
}