#include <array>

template <typename... T>
struct sum_wrapper
{
    sum_wrapper(T... args)
    {
        value = (... + args);
    }

    std::common_type_t<T...> value;
};

template <typename... T>
void parenthesized(T... args)
{
    std::array<std::common_type_t<T...>, sizeof...(T)> arr {args...};   // std::array<int,4> {1, 2, 3, 4}

    sum_wrapper sw1(args...);     // value = 1 + 2 + 3 + 4
    sum_wrapper sw2(++args...);   // value = 2 + 3 + 4 + 5
}

int main(){
    parenthesized(1, 2, 3, 4);
    return 0;
}