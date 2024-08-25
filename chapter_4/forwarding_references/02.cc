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

int main() {
    foo x = { 42 };   // x is l-value
    foo& rx = x;      // rx is l-value

    g(x);             // g(foo&)
    g(rx);            // g(foo&)
    g(foo{ 42 });     // g(foo&&)
    return 0 ;
}