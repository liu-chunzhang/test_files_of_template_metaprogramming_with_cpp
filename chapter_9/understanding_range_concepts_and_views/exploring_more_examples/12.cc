#include <algorithm>
#include <array>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1 , 2 , 3 , 4 };

    for( auto i : v | rv::adjacent<2> )
    {
        std::cout << std::format("({},{})",i.first,i.second) ;
    }

    return 0;
}