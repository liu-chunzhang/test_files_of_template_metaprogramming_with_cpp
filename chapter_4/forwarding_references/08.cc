#include <vector>

int main() {
    int x = 42;
    auto&& rx = x;          // int&
    auto&& rc = 42;         // int&&
    auto const&& rcx = x;   // error

    std::vector<int> v{ 42 };
    auto&& rv = v[0];       // int&
    return 0;
}