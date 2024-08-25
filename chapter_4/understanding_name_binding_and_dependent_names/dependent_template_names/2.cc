#include <iostream>

template <typename T>
struct base_parser
{
    template <typename U>
    struct token {};
};

template <typename T>
struct parser : base_parser<T>
{
    void parse()
    {
        using token_type = base_parser<T>::template token<int>;
        token_type t1{};

        typename base_parser<T>::template token<int> t2{};

        std::cout << "parse\n";
    }
};

int main() {

    return 0 ;
}