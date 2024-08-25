#include <iostream>

struct account_t
{
    int         number;
};

template <typename T>
struct wrapper
{
    T data;
};

template<template<typename> typename TT>
void process15(TT<account_t>) { std::cout << "TT<C>" << '\n'; }

int main() {
    
    wrapper<account_t>  wa{ { 42 } } ;
    process15(wa) ;                     // TT<C>
    return 0 ;
}
