#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1, 5, 3, 2, 8, 7, 6, 4 };

    std::ranges::sort(v);
    auto r =
        rv::transform(
        rv::reverse(
            rv::drop(
                rv::filter(v,
                            [](int const n) {return n % 2 == 0; }),
                2)),
        [](int const n) {return n * n; });

    std::ranges::for_each(r, [](int const n) {std::cout << n << '\n'; });
    return 0;
}