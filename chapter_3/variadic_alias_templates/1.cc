#include <concepts>

template <typename T, typename... Args>
struct foo 
{
};

template <typename... Args>
using int_foo = foo<int, Args...>;

int main(){
    [[maybe_unused]] foo<double, char, int> f1;
    foo<int, char, double> f2;
    int_foo<char, double> f3;
    static_assert(std::is_same_v<decltype(f2), decltype(f3)>);
    return 0;
}