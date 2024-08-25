#include <string>

template <typename T>
requires std::is_arithmetic_v<T>
struct container
{ /* ... */ };

template <typename T>
concept containerizeable = requires {
    typename container<T>;
};

int main(){
    static_assert(containerizeable<int>);
    static_assert(!containerizeable<std::string>);
    return 0;
}
