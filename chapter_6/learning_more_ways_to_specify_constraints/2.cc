#include <iostream>

using namespace std::string_literals;

template <typename T>
    requires requires(T a, T b) { a + b; }  // requires clause with requires expression
auto add(T a, T b)
{
    return a + b;
}

int main(){
    std::cout << add( 3 , 4 ) << '\n' ;
    std::cout << add( 3.6 , 4.6 ) << '\n' ;
    std::cout << add( "3"s , "4"s ) << '\n' ;
    return 0;
}