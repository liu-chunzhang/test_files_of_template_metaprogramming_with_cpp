#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1, 5, 3, 2, 4, 7, 6, 8 };

    for (auto i :
        v |
        rv::reverse |
        rv::filter([](int const n) {return n % 2 == 1; }) |
        rv::take(2))
    {
        std::cout << i << '\n';     // prints 7 amd 3
    }
    return 0;
}