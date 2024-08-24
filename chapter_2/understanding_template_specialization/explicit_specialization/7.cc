#include <iostream>

template <typename T, typename U>
void func(T a, U b)
{
    std::cout << "primary template\n";
}

template <>
void func(int a, int b)
{
    std::cout << "int-int specialization\n";
}

template <>
void func(int a, double b)
{
    std::cout << "int-double specialization\n";
}

int main(){
    func(1, 2);
    func(1, 2.0);
    func(1.0, 2.0);
    return 0;
}