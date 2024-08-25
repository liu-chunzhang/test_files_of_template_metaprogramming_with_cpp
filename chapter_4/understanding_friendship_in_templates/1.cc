#include <iostream>

struct wrapper
{   
    wrapper(int const v) :value(v)
    {}
private:
    int value;

    friend void print(wrapper const & w);
};

void print(wrapper const& w)
{
    std::cout << w.value << '\n';
}

int main(){
    wrapper w{ 42 };
    print(w);
    return 0;
}

