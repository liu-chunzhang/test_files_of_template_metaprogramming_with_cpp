#include <algorithm>
#include <array>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::array<int, 4> a{ 1, 2, 3, 4 };
    std::vector<double> v{ 10.0, 20.0, 30.0 };

    auto z = rv::zip_transform(std::multiplies<double>(), a, v) ; // { {1, 10.0}, {2, 20.0}, {3, 30.0} }
    return 0;
}