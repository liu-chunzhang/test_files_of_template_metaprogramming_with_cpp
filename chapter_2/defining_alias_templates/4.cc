#include <vector>

template <typename T, size_t S>
struct list
{
    using type = std::vector<T>;
};

template <typename T>
struct list<T, 1>
{
    using type = T;
};

template <typename T, size_t S>
using list_t = typename list<T, S>::type;

int main(){
    static_assert(std::is_same_v<list_t<int, 1>, int>);
    static_assert(std::is_same_v<list_t<int, 2>, std::vector<int>>);
    return 0;
}