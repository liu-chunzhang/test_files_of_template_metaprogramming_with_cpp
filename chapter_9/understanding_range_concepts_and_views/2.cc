#include <iostream>
#include <ranges>

int main(){
    for (auto i : std::ranges::iota_view(1, 10))
        std::cout << i << '\n';

    std::cout << '\n' ;

    for (auto i : std::views::iota(1, 10))
        std::cout << i << '\n';
    return 0;
}