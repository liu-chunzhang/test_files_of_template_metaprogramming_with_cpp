#include <algorithm>
#include <ranges>
#include <vector>

int main(){
    auto l_odd = [](int const n) {return n % 2 == 1; };

    std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };
    std::vector<int> o;
    auto e1 = std::ranges::copy_if(v, std::back_inserter(o), l_odd);

    int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
    auto e2 = std::ranges::copy_if(arr, std::back_inserter(o), l_odd);

    auto r = std::ranges::views::iota(1, 10);
    auto e3 = std::ranges::copy_if(r, std::back_inserter(o), l_odd);
    return 0;
}


