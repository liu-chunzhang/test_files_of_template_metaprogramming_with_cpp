#include <iostream>

template <typename T>
struct wrapper
{
    wrapper(T const v) :value(v) {}
private:
    T value;

    friend void print(wrapper<int> const&);
};

void print(wrapper<int> const& w)
{
    std::cout << w.value << '\n';
}

void print(wrapper<char> const& w)
{
    std::cout << w.value << '\n'; // error
}

int main(){
    wrapper w{ 42 };
    print(w);

    wrapper w_2{ 'a' } ;
    print(w_2);
    return 0;
}