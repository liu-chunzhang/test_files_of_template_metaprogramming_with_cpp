#include <iostream>

using namespace std::string_literals;

template<typename T>
concept arithmetic = std::is_arithmetic_v<T>; 

template <arithmetic T>
T add(T const a, T const b) 
{
    return a + b;
}

template <arithmetic T>
T mul(T const a, T const b) 
{
    return a * b;
}

int main(){
    std::cout << add( 4.2 , 3.0 ) << std::endl;
    std::cout << add( "4.2"s , "3.0"s ) << std::endl;

    std::cout << mul( 4.2 , 3.0 ) << std::endl;
    std::cout << mul( "42"s , "a"s ) << std::endl;
    return 0;
}