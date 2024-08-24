#include <algorithm>
#include <iostream>

int main(){
    int arr[] = { 1,6,3,8,4,2,9 };
    std::sort(
        std::begin(arr), std::end(arr),
        [](int const a, int const b) {return a > b; });

    int pivot = 5;
    auto count = std::count_if(
        std::begin(arr), std::end(arr),
        [pivot](int const a) {return a > pivot; });

    std::cout << count << '\n';
    return 0;
}