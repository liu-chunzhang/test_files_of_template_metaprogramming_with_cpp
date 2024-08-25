#include <iostream>

struct account_t
{
    int         number;
};

template<typename T>
void process08(T(*)()) 
{ std::cout << "T (*)()" << '\n'; }

template<typename T>
void process08(account_t(*)(T)) 
{ std::cout << "C (*)(T)" << '\n'; }

template<typename T, typename U>
void process08(T(*)(U)) 
{ std::cout << "T (*)(U)" << '\n'; }

int main() {
    account_t   (*pf1)() = nullptr ;
    account_t   (*pf2)(int) = nullptr ;
    double      (*pf3)(int) = nullptr ;

    process08(pf1) ;       // T(*)()
    process08(pf2) ;       // C(*)(T)
    process08(pf3) ;       // T(*)(U)
    return 0 ;
}
