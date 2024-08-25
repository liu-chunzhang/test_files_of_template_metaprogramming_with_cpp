#include <iostream>

struct account_t
{
    int         number;
};

struct balance_t
{
    account_t account;
    double    amount;
};

template<typename T>
void process10(T account_t::*)
{ std::cout << "T C::*" << '\n'; }

template<typename T>
void process10(account_t T::*)
{ std::cout << "C T::*" << '\n'; }

template<typename T, typename U>
void process10(T U::*)
{ std::cout << "T U::*" << '\n'; }

int main() {

    process10(&account_t::number);   // T C::*
    process10(&balance_t::account);  // C T::*
    process10(&balance_t::amount);   // T U::*
    return 0 ;
}
