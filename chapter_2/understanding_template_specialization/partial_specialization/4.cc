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

template <size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<char, S> const& arr)
{
    os << '[';
    for (auto const& e : arr)
        os << e;
    os << ']';

    return os;
}

int main(){
    std::array<char, 9> str;
    std::strcpy(str.data(), "template");
    pretty_print(std::cout, str);   // [template]
    return 0;
}