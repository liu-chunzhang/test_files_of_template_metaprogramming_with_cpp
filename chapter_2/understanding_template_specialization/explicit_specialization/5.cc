#include <iostream>

template <typename T>
struct foo {};

template <typename T>
void func(foo<T>)
{
    std::cout << "primary template\n";
}

template<>
void func(foo<int>)
{
    std::cout << "int specialization\n";
}

int main(){
    func(foo<int>{});
    func(foo<double>{});
    return 0;
}