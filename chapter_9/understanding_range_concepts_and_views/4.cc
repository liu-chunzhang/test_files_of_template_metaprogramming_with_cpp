#include <algorithm>
#include <iostream>
#include <ranges>

int main(){
    auto v1 = std::ranges::views::iota(1, 10);
    std::ranges::for_each(v1, [](int const n) {std::cout << n << '\n'; });

    std::cout << '\n' ;

    auto v2 =   std::ranges::views::iota(1) |
                std::ranges::views::take(9);
    std::ranges::for_each(v2, [](int const n) {std::cout << n << '\n'; });
    return 0;
}