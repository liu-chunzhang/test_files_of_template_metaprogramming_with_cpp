#include <iostream>
#include <ranges>
#include <vector>

int main(){
    namespace rv = std::ranges::views;

    std::string text{ "this is a demo!" };
    constexpr std::string_view delim{ " " };
    for (auto const word : text | rv::split(delim))
    {
        std::cout << std::string_view(word.begin(), word.end()) << '\n';
    }
    return 0;
}