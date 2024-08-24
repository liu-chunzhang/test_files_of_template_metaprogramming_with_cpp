#include <iostream>

template <typename T>
struct foo
{
    static T value;
};

template <typename T> T foo<T>::value = 0;

template <> int foo<int>::value = 42;

int main(){
    foo<double> a, b;
    std::cout << a.value << '\n';
    std::cout << b.value << '\n';

    foo<int> c;
    std::cout << c.value << '\n';

    a.value = 100;
    std::cout << a.value << '\n';
    std::cout << b.value << '\n';
    std::cout << c.value << '\n';
    return 0;
}