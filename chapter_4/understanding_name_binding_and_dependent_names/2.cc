#include <iostream>

template <typename T>
struct handler          // [1] template definition
{
    void handle(T value)
    {
        std::cout << "handler<T>: " << value << '\n';
    }
};

template <typename T>
struct parser           // [2] template definition
{
    void parse(T arg)
    {
        arg.handle(42.0);   // [3] dependent name
    }
};

template <>
struct handler<int>     // [4] template specialization
{
    void handle(int value)
    {
        std::cout << "handler<int>: " << value << '\n';
    }
};

int main(){
    handler<int>            h ;
    parser<handler<int>>    p ;
    p.parse(h) ;
    return 0 ;
}