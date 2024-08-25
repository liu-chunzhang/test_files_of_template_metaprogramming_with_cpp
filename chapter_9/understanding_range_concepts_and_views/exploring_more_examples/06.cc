#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<std::tuple<int, double, std::string>> v = 
        { 
            {1, 1.1, "one"}, 
            {2, 2.2, "two"}, 
            {3, 3.3, "three"}
        };

    std::cout << "keys:\n";
    for (auto i : v | rv::keys)
        std::cout << i << '\n';

    std::cout << "values:\n";
    for (auto i : v | rv::values)
        std::cout << i << '\n';

    std::cout << "elements:\n";
    for (auto i : v | rv::elements<2>)
        std::cout << i << '\n';
    return 0;
}