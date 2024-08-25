#include <iostream>
#include <type_traits>

struct foo
{
    int a;
};

struct bar
{
    int a = 0;
};

struct tar
{
    int a = 0;
    tar() : a(0) {}
};

int main(){
    std::cout << std::boolalpha;
    std::cout << std::is_trivial_v<foo> << '\n';                // true
    std::cout << std::is_trivial_v<bar> << '\n';                // false
    std::cout << std::is_trivial_v<tar> << '\n';                // false

    std::cout << std::is_trivially_copyable_v<foo> << '\n';     // true
    std::cout << std::is_trivially_copyable_v<bar> << '\n';     // true
    std::cout << std::is_trivially_copyable_v<tar> << '\n';     // true
    return 0;
}