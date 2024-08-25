#include <iostream>

struct account_t
{
    int         number;
};

template <typename T>
void process06(T[5]) 
{ std::cout << "T[5]" << '\n'; }

template <size_t n>
void process07(account_t[5][n]) 
{ std::cout << "C[5][n]" << '\n'; }

int main() {
    account_t arr1[5] {} ;
    process06(arr1) ;       // T[5]

    account_t ac{ 42 } ;
    process06(&ac) ;        // T[5]

    account_t arr2[5][3] ;
    process07(arr2) ;       // C[5][n]
    return 0 ;
}
