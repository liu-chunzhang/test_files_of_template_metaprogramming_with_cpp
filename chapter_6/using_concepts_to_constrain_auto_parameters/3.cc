#include <concepts>

auto add(std::integral auto ... args)
{
    return (args + ...);
}

int main(){
    add(4, 2);
    add(4.0, 2);
    return 0;
}