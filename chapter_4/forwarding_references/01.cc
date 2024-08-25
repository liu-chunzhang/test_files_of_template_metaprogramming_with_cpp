#include <iostream>

struct foo
{
    int data;
};

void f(foo& v)
{
std::cout << "f(foo&)\n";
}

#ifdef CHANGED
void f(const foo& v)
{
std::cout << "f(const foo& v)\n";
}
#endif // CHANGED

int main() {
    foo x = { 42 };   // x is l-value
    foo& rx = x;      // rx is l-value

    f(x);             // f(foo&)
    f(rx);            // f(foo&)
    f(foo{ 42 });     // error, a non-const reference may only be bound to an lvalue
    return 0 ;
}