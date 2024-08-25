#include <iostream>

template <typename T>
struct wrapper
{
    T data;
};

template<typename T>
void process11(wrapper<T>)
{ std::cout << "C<T>" << '\n'; }

int main() {

    wrapper<double> wd{ 42.0 };
    process11(wd); // C<T>
    return 0 ;
}
