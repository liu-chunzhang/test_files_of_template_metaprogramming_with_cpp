#include <iostream>

struct account_t
{
    int         number;
};

template <typename T>
void process04(T*) 
{ std::cout << "T*" << '\n'; }

template <typename T>
void process04(T&) 
{ std::cout << "T&" << '\n'; }

template <typename T>
void process05(T&&) 
{ std::cout << "T&&" << '\n'; }

int main() {
    account_t ac{42} ;
    process04(&ac) ;    // T*
    process04(ac) ;     // T&
    process05(ac) ;     // T&&
    return 0 ;
}
