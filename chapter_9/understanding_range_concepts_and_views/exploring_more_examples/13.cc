#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1 , 2 , 3 , 4 , 5 };

    for( auto i : v | rv::adjacent_transform<3>( std::multiplies() ) )  // In current C++23, it is impossible to realize.
    {
        std::cout << i << ' ' ; // prints: 3 24 60
    }

    return 0;
}