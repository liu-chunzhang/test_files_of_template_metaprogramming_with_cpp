#include <iostream>
#include <vector>

template <typename T>
void f(T&& arg)               // forwarding reference
{ std::cout << "f(T&&)\n"; }

template <typename T>
void f(T const&& arg)         // rvalue reference
{ std::cout << "f(T const&&)\n"; }

template <typename T>
void f(std::vector<T>&& arg)  // rvalue reference
{ std::cout << "f(vector<T>&&)\n"; }

template <typename T>
struct S
{
    void f(T&& arg)            // rvalue reference
    { std::cout << "S.f(T&&)\n"; }
};

int main(){
    int x = 42;
    f(x);                   // f(T&&)
    f(42);                  // f(T&&)

    int const cx = 100;
    f(cx);                  // f(T&&)
    f(std::move(cx));       // f(T const&&)

    std::vector<int> v{ 42 };
    f(v);                   // f(T&&)
    f(std::vector<int>{42});// f(vector<T>&&)

    S<int> s;
    s.f(x);                 // error
    s.f(42);                // S.f(T&&)
    return 0 ;
}