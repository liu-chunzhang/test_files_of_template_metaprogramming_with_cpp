#include <string>

auto add(auto a, auto b)
{
    return a + b;
}

template<>
auto add(char const* a, char const* b)
{
    return std::string(a) + std::string(b);
}

int main(){
    add(4, 2);
    add(4.0, 2);
    add("4", "2");
    return 0;
}