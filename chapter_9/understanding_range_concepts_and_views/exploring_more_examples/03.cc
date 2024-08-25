#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::vector<int> v{ 1, 5, 3, 2, 4, 7, 6, 8 };

    auto r1 = rv::take(v, 2);
    auto r2 = rv::take(2)(v);
    auto r3 = v | rv::take(2);
    return 0;
}