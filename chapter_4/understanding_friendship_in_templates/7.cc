#include <iostream>

template <typename T>
struct wrapper;

template <typename T>
void print(wrapper<T> const& w) ;

template <typename T>
struct printer;

template <typename T>
struct wrapper
{
    wrapper(T const v) :value(v) {}
private:
    T value;

    friend void print<T>(wrapper<T> const&);
    friend struct printer<T>;
};

template <typename T>
void print(wrapper<T> const& w)
{
    std::cout << w.value << '\n';
}

template <typename T>
struct printer
{
    void operator()(wrapper<T> const& w)
    {
        std::cout << w.value << '\n';
    }
};

int main() {
    wrapper w1{ 43 };
    print(w1);
    printer<int>()(w1);

    wrapper w2{ 'a' };
    print(w2);
    printer<char>()(w2);
    return 0;
}