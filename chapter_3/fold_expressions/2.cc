#include <iostream>

template <typename... T>
void printl(T... args)
{
    (..., (std::cout << args)) << '\n';
}

template <typename... T>
void printr(T... args)
{
    ((std::cout << args), ...) << '\n';
}

int main(){
    printl('d', 'o', 'g');  // dog
    printr('d', 'o', 'g');  // dog
    return 0;
}