#include <iostream>

template <typename T>
struct wrapper
{
    T data;
};

template<template<typename> class TT, typename T>
void process13(TT<T>) { std::cout << "TT<T>\n"; }

int main() {

    wrapper<double> wd{ 42.0 };
    process13(wd);              // TT<U>
    return 0 ;
}
