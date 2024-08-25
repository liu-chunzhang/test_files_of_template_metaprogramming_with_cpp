#include <iostream>

template <typename T>
struct base_parser
{
    using value_type = T;
};

template <typename T>
struct parser : base_parser<T>
{
    void parse()
    {
        //value_type v{}; //syntax error: unexpected token 'identifier', expected ';'
        //base_parser<T>::value_type v{}; // error: need ‘typename’ before ‘base_parser<T>::value_type’ because ‘base_parser<T>’ is a dependent scope
        typename base_parser<T>::value_type v{};

        std::cout << "parse\n";
    }
};

int main() {
    parser<int> p ;
    p.parse() ;
    return 0 ;
}