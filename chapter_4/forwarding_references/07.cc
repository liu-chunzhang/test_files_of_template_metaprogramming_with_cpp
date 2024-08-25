#include <iostream>

int main(){
    using lrefint = int&;
    using rrefint = int&&;
    int x = 42;
    lrefint& r1 = x;    // type of r1 is int&
    lrefint&& r2 = x;   // type of r2 is int&
    rrefint& r3 = x;    // type of r3 is int&
    rrefint&& r4 = 1;   // type of r4 is int&&

    std::cout << typeid( r1 ).name() << '\n' ;
    std::cout << typeid( r2 ).name() << '\n' ;
    std::cout << typeid( r3 ).name() << '\n' ;
    std::cout << typeid( r4 ).name() << '\n' ;
    return 0;
}