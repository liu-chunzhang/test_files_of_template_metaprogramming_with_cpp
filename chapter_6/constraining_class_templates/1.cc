#include <concepts>

template <std::integral T>
struct wrapper
{
    T value;
};

int main(){
    wrapper<int> a{ 42 };
    wrapper<double> b{ 42.0 }; // error
    return 0;
}