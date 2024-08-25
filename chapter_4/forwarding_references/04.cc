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

void h(foo& v)
{
    g(v);
}

void h(foo&& v)
{
    g(v);
}

int main(){
    foo x{ 42 };

    h(x);          // g(foo&)
    h(foo{ 42 });  // g(foo&)
    return 0 ;
}
