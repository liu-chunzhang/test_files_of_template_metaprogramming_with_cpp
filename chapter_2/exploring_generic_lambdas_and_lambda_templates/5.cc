#include <array>
#include <iostream>
#include <numeric>

int main(){
    auto l = []<typename T, size_t N>(std::array<T, N> const& arr) { return std::accumulate(arr.begin(), arr.end(), static_cast<T>(0)); };

    auto v1 = l(1); // error
    auto v2 = l(std::array<int, 3>{1, 2, 3});
    return 0;
}