#include <iostream>

template <typename T, size_t N>
void handle(T(&arr)[N], char(*)[N % 2 == 0] = 0)
{
    std::cout << "handle even array\n";
}

template <typename T, size_t N>
void handle(T(&arr)[N], char(*)[N % 2 == 1] = 0)
{
    std::cout << "handle odd array\n";
}

int main(){
    int arr1[]{ 1,2,3,4,5 };
    handle(arr1);

    int arr2[]{ 1,2,3,4 };
    handle(arr2);
    return 0;
}