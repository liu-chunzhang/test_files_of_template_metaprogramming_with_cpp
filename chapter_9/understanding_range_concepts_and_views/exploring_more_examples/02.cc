#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1, 5, 3, 2, 4, 7, 6, 8 };
    auto r1 = rv::reverse(v);
    auto r2 = v | rv::reverse;
    return 0;
}