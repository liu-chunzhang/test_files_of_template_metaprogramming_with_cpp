#include <iostream>

template <size_t i>
struct int_array
{
    int data[i];
};

template<template<size_t> typename TT, size_t i>
void process14(TT<i>) { std::cout << "TT<i>" << '\n'; }

int main() {

    int_array<5> ia{};
    process14(ia);      // TT<i>
    return 0 ;
}
