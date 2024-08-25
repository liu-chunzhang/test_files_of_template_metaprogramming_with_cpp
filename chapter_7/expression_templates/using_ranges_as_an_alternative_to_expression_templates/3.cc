#include <iostream>
#include <functional>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v1{ 1, 2, 3 };
    std::vector<int> v2{ 4, 5, 6 };
    double a{ 1.5 };

    auto sv2 = v2 | rv::transform([&a](int val) {return a * val; });
    auto v3 = rv::zip_view(std::plus<>{}, v1, sv2);

    for (auto e : sv2)
        std::cout << e << '\n';
    return 0;
}