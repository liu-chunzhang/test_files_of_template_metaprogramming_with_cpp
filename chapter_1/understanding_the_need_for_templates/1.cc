#include <iostream>

int max( const int a , const int b ) {
    return a > b ? a : b ;
}

double max( const double a , const double b ) {
    return a > b ? a : b ;
}

int main(){
    std::cout << max( 1 , 2 ) << '\n' ;
    std::cout << max( 3.4 , 4.2 ) << '\n' ;
    return 0;
}