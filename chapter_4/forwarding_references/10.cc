#include <iostream>

struct foo
{
    int data;
};

void g(foo& v)
{
    std::cout << "g(foo&)\n";
}

void g(foo&& v)
{
    std::cout << "g(foo&&)\n";
}

template <typename T>
void h(T&& v)
{
    g(std::forward<T>(v));
}

int main(){
    foo x{ 42 };

    h(x);          // g(foo&)
    h(foo{ 42 });  // g(foo&&)
    return 0;
}