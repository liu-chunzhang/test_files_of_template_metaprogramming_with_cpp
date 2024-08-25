#include <iostream>

using namespace std::string_literals;

template <typename T>      
T mul(T const a, T const b) requires std::is_arithmetic_v<T>
{
    return a * b;
}

int main(){
    std::cout << mul( 4.2 , 3.0 ) << std::endl;
    std::cout << mul( "42"s , "a"s ) << std::endl;
    return 0;
}