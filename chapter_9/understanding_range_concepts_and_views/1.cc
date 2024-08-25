#include <iostream>
#include <vector>
#include <ranges>

int main(){
    std::vector<int> v{ 8, 5, 3, 2, 4, 7, 6, 1 };
    auto r = std::views::iota(1, 10);

    std::cout << "size(v)=" << std::ranges::size(v) << '\n';
    std::cout << "size(r)=" << std::ranges::size(r) << '\n';

    std::cout << "empty(v)=" << std::ranges::empty(v) << '\n';
    std::cout << "empty(r)=" << std::ranges::empty(r) << '\n';

    std::cout << "first(v)=" << *std::ranges::begin(v) << '\n';
    std::cout << "first(r)=" << *std::ranges::begin(r) << '\n';

    std::cout << "rbegin(v)=" << *std::ranges::rbegin(v) << '\n';
    std::cout << "rbegin(r)=" << *std::ranges::rbegin(r) << '\n';

    std::cout << "data(v)=" << *std::ranges::data(v) << '\n';   
    return 0;
}
