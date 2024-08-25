#include <concepts>

auto add(std::integral auto a, std::integral auto b)
{
    return a + b;
}

int main(){
    add(4, 2);
    add(4.0, 2);
    return 0;
}