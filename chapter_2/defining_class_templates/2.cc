#include <iostream>

template <typename T>
class wrapper ;                         // OK

void use_wrapper(wrapper<int>* ptr) ;   // OK

int main(){
    wrapper<int> a(42);          // error, incomplete type
    use_wrapper(&a);
    return 0;
}

template <typename T>
class wrapper
{
public:
    wrapper(T const v) :value(v)
    {
    }

    T const& get() const { return value; }
private:
    T value;
};

void use_wrapper(wrapper<int>* ptr)
{
    std::cout << ptr->get() << '\n';
}