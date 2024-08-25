#include <utility>
#include <string>

namespace std {
    template <typename T>
    pair(T&&, char const*) -> pair<T, std::string>;

    template <typename T>
    pair(char const*, T&&) -> pair<std::string, T>;

    pair(char const*, char const*) -> pair<std::string, std::string>;
}

int main() {
    std::pair<int, std::string> p1{ 1, "one" };  // [1] OK
    std::pair p2{ 2, "two" };                    // [2] OK
    std::pair<> p3{ 3, "three" };                // [3] error
    std::pair<int> p4{ 4, "four" };              // [4] error
    return 0 ;
}