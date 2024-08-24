#include <array>
#include <cstring>
#include <iostream>

template <typename T, size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<T, S> const& arr)
{
    os << '[';
    if (S > 0)
    {
        size_t i = 0;
        for (; i < S - 2; ++i)
            os << arr[i] << ',';
        os << arr[S - 2];
    }
    os << ']';

    return os;
}

int main(){
    std::array<int, 9> arr {1, 1, 2, 3, 5, 8, 13, 21};
    pretty_print(std::cout, arr);       // [1,1,2,3,5,8,13,21]

    std::cout << '\n' ;

    std::array<char, 9> str;
    std::strcpy(str.data(), "template");
    pretty_print(std::cout, str);       // [t,e,m,p,l,a,t,e]
    std::cout << '\n' ;
    return 0;
}