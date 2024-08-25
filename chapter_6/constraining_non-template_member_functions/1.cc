#include <iostream>

template <typename T>
struct wrapper
{
    T value;

    bool operator==(std::string_view str)
    requires std::is_convertible_v<T, std::string_view>
    {
        return value == str;
    }
};

int main(){
    wrapper<int> a{ 42 };
    wrapper<char const*> b{ "42" };

    if(a == 42) {}      // error
    if(b == "42") {}
    return 0;
}