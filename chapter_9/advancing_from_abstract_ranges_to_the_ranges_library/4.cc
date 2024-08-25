#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

int main(){
    std::vector<int> v{ 1, 5, 3, 2, 8, 7, 6, 4 };

    std::ranges::sort(v);
    auto r =
        v
        | std::ranges::views::filter([](int const n) {return n % 2 == 0; })
        | std::ranges::views::drop(2)
        | std::ranges::views::reverse
        | std::ranges::views::transform([](int const n) {return n * n; });

    std::ranges::for_each(r, [](int const n) {std::cout << n << '\n'; });
    return 0;
}