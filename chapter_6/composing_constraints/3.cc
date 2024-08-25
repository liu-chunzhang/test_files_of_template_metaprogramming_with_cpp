#include <iostream>

using namespace std::string_literals;

template <typename T>
requires std::is_integral_v<T> || std::is_floating_point_v<T>
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