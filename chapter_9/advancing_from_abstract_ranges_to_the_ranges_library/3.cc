#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v{ 1, 5, 3, 2, 8, 7, 6, 4 };

    // copy only the even elements
    std::vector<int> temp;
    std::copy_if(v.begin(), v.end(), std::back_inserter( temp ) , [](int const n) {return n % 2 == 0; });

    // sort the sequence
    std::sort(temp.begin(), temp.end(), [](int const a, int const b) {return a > b; });

    // remove the first two
    temp.erase(temp.begin() + temp.size() - 2, temp.end());

    // transform the elements
    std::transform(temp.begin(), temp.end(), temp.begin(), [](int const n) {return n * n; });

    // print each element
    std::for_each(temp.begin(), temp.end(), [](int const n) {std::cout << n << '\n'; });
    return 0;
}