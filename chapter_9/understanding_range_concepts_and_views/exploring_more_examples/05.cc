#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1, 5, 3, 2, 4, 7, 16, 8 };
    for (auto i : v |
        rv::take_while([](int const n) {return n < 10; }) |
        rv::drop_while([](int const n) {return n % 2 == 1; })
        )
    {
        std::cout << i << '\n'; // prints 2 4 7
    }
    return 0;
}