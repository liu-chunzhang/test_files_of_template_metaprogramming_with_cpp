#include <iostream>

using namespace std::string_literals;

template <typename T>
T add(T const a, T const b)
{
    return a + b;
}

int main(){
    std::cout << add(42, 1) << '\n';
    std::cout << add(42.0, 1.0) << '\n';
    std::cout << add("42"s, "1"s) << '\n';
    //std::cout << add("42", "1") << '\n';   // error: cannot add two pointers
    return 0;
}