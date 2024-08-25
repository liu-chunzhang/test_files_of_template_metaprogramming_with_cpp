#include <iostream>

struct foo
{
    int data;
};

void h(foo&& v)
{
    std::cout << "h(foo&&)\n";
}

int main() {
    foo x = { 42 };     // x is l-value
    foo& rx = x;        // rx is l-value

    h(x);               // error, cannot bind an lvalue to an rvalue reference
    h(rx);              // error
    h(foo{ 42 });       // h(foo&&)
    h(std::move(x));    // h(foo&&)
    return 0 ;
}