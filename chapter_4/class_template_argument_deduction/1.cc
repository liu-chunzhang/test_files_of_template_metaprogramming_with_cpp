#include <utility>
#include <vector>

template <typename T>
struct wrapper
{
    T data;
};

int main() {
    std::pair<int, double> p{ 42, 42.0 };
    std::vector<int> v{ 1,2,3,4,5 };
    wrapper<int> w{ 42 };
    return 0 ;
}
