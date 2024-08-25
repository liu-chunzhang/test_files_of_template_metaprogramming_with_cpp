#include <iostream>

int main(){
    int a = 42;
    decltype(a = 1) e = a;
    std::cout << a << '\n';
    return 0;
}