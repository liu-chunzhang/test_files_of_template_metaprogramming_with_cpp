#include <iostream>

template <typename T, typename... Ts>
struct tuple
{
    tuple(T const& t, Ts const &... ts)
        : value(t), rest(ts...)
    {
    }

    constexpr int size() const { return 1 + rest.size(); }

    T value;
    tuple<Ts...> rest;
};

template <typename T>
struct tuple<T>
{
    tuple(const T& t)
        : value(t)
    {
    }

    constexpr int size() const { return 1; }

    T value;
};

int main(){
    tuple<int> one(42);
    tuple<int, double> two(42, 24.5);
    tuple<int, double, char> three(42, 24.5, 'a');

    std::cout << one.value << '\n';
    std::cout << two.value << ',' 
            << two.rest.value << '\n';
    std::cout << three.value << ',' 
            << three.rest.value << ','
            << three.rest.rest.value << '\n';
    return 0;
}