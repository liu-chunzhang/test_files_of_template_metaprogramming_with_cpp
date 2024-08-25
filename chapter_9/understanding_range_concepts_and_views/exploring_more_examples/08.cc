#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<std::vector<int>> v{ {1,2,3}, {4}, {5, 6} };

    for(int const i : v | rv::join_with(0))
        std::cout << i << ' ';  // print 1 2 3 0 4 0 5 6
    return 0;
}