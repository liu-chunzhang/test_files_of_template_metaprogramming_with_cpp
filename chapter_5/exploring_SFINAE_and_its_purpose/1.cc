#include <array>
#include <iostream>

template <typename T>
auto my_begin(T& c) { return c.begin(); }

template <typename T, size_t N>
T* my_begin(T(&arr)[N]) { return arr; }

int main(){
    std::array<int, 5> arr1{ 1,2,3,4,5 };
    std::cout << *my_begin(arr1) << '\n';

    int arr2[]{ 5,4,3,2,1 };
    std::cout << *my_begin(arr2) << '\n';
    return 0;
}