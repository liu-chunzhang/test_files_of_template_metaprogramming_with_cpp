#include <iostream>

struct account_t
{
    int         number;
};

template <typename T>
void process01(T) 
{ std::cout << "T" << '\n'; }

template <typename T>
void process02(T const) 
{ std::cout << "T const" << '\n'; }

template <typename T>
void process03(T volatile) 
{ std::cout << "T volatile" << '\n'; }

int main() {
    account_t ac{42} ;
    process01(ac) ;     // T
    process02(ac) ;     // T const
    process03(ac) ;     // T volatile
    return 0 ;
}
