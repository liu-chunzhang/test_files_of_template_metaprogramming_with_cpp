#include <iostream>

template <typename T>
struct base_parser
{
    template <typename U>
    void init()
    {
        std::cout << "init\n";
    }
};

template <typename T>
struct parser : base_parser<T>
{
    void parse()
    {
        //base_parser<T>::init<int>(); // error with warning: expected ‘template’ keyword before dependent template name [-Wmissing-template-keyword]
        base_parser<T>::template init<int>();

        std::cout << "parse\n";
    }
};

int main() {

    return 0 ;
}