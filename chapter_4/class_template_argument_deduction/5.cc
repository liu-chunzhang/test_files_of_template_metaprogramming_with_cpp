#include <iostream>
#include <utility>

#ifdef CHANGED
namespace std {
    template <typename T>
    pair(T&&, char const*) -> pair<T, std::string>;

    template <typename T>
    pair(char const*, T&&) -> pair<std::string, T>;

    pair(char const*, char const*) -> pair<std::string, std::string>;
}
#endif // CHANGED

int main() {
    std::pair  p1{ 1, "one" };       // std::pair<int, std::string>
    std::cout << typeid(p1).name() << '\n' ;

    std::pair  p2{ "two", 2 };       // std::pair<std::string, int>
    std::cout << typeid(p2).name() << '\n' ;

    std::pair  p3{ "3", "three" };   // std::pair<std::string, std::string>
    std::cout << typeid(p3).name() << '\n' ;
    
    return 0 ;
}