#include <iostream>

using namespace std::string_literals;

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template <typename T>
concept Number = Integral<T> || FloatingPoint<T>;

template <Number T>
T add(T a, T b)
{
    return a + b;
}

int main(){
    std::cout << "add( 3 , 4 ) = " << add( 3 , 4 ) << '\n' ;
    std::cout << "add( 3.6 , 4.6 ) = " << add( 3.6 , 4.6 ) << '\n' ;
    std::cout << "add( '3's , '4's ) = " << add( "3"s , "4"s ) << '\n' ;
    return 0;
}