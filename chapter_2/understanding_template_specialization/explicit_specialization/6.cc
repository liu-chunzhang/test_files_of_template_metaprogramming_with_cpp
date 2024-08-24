#include <iostream>

template <typename T>
void func( T a ) {
    std::cout << "primary template\n" ;
}

template <>
void func( int a = 0 ) {    // error: default argument
    std::cout << "int specialization\n" ;
}

int main() {
    func(42.0);
    func(42);
    return 0 ;
}