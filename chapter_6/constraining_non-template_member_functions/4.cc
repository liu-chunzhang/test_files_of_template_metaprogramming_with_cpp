#include <memory>

template <typename T>
struct wrapper
{
    T value;

    wrapper(T const& v) 
        requires std::is_copy_constructible_v<T> 
    :value(v) {}
};

int main(){
    wrapper<int> a = 42;

    wrapper<std::unique_ptr<int>> p = std::make_unique<int>(42); // error
    return 0;
}