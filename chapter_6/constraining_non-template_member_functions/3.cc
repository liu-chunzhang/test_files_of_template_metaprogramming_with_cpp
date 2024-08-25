#include <memory>

template <typename T>
struct wrapper
{
    T value;

    template <typename U, typename = std::enable_if_t<std::is_copy_constructible_v<U> && std::is_convertible_v<U, T>>>
    wrapper(U const& v) :value(v) {}
};

int main(){
    wrapper<int> a = 42;

    wrapper<std::unique_ptr<int>> p = std::make_unique<int>(42); // error
    return 0;
}