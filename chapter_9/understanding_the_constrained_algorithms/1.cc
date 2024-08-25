#include <algorithm>
#include <vector>

int main(){
    auto l_odd = [](int const n) {return n % 2 == 1; };

    std::vector<int> v{ 1, 1, 2, 3, 5, 8, 13 };
    std::vector<int> o;
    auto e1 = std::copy_if(v.begin(), v.end(), std::back_inserter(o), l_odd);

    int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
    auto e2 = std::copy_if(std::begin(arr), std::end(arr), std::back_inserter(o), l_odd);
    return 0;
}