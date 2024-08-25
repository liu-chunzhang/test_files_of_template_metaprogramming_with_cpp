#include <iostream>

struct account_t
{
    int         number;

    int get_number() { return number; }
    int from_string(std::string text) { return std::atoi(text.c_str()); }
};

struct transaction_t
{
    double amount;
};

struct balance_report_t {};

struct balance_t
{
    account_t account;
    double    amount;

    account_t get_account() { return account; }
    int get_account_number() { return account.number; }
    bool can_withdraw(double const value) { return amount >= value; };
    transaction_t withdraw(double const value) { amount -= value; return transaction_t{ -value }; }
    balance_report_t make_report(int const type) { return {}; }
};

template<typename T>
void process09(T(account_t::*)())
{ std::cout << "T (C::*)()" << '\n'; }

template<typename T, typename U>
void process09(T(account_t::*)(U))
{ std::cout << "T (C::*)(U)" << '\n'; }

template<typename T, typename U>
void process09(T(U::*)())
{ std::cout << "T (U::*)()" << '\n'; }

template<typename T, typename U, typename V>
void process09(T(U::*)(V))
{ std::cout << "T (U::*)(V)" << '\n'; }

template<typename T>
void process09(account_t(T::*)())
{ std::cout << "C (T::*)()" << '\n'; }

template<typename T, typename U>
void process09(transaction_t(T::*)(U))
{ std::cout << "C (T::*)(U)" << '\n'; }

template<typename T>
void process09(balance_report_t(balance_t::*)(T))
{ std::cout << "D (C::*)(T)" << '\n'; }

int main() {

    int (account_t:: * pfm1)() = &account_t::get_number;
    int (account_t:: * pfm2)(std::string) = &account_t::from_string;
    int (balance_t:: * pfm3)() = &balance_t::get_account_number;
    bool (balance_t:: * pfm4)(double) = &balance_t::can_withdraw;
    account_t(balance_t:: * pfm5)() = &balance_t::get_account;
    transaction_t(balance_t:: * pfm6)(double) = &balance_t::withdraw;
    balance_report_t(balance_t:: * pfm7)(int) = &balance_t::make_report;

    process09(pfm1);    // T (C::*)()
    process09(pfm2);    // T (C::*)(U)
    process09(pfm3);    // T (U::*)()
    process09(pfm4);    // T (U::*)(V)
    process09(pfm5);    // C (T::*)()
    process09(pfm6);    // C (T::*)(U)
    process09(pfm7);    // D (C::*)(T)
    return 0 ;
}
