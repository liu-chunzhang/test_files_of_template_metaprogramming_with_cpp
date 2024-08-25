#include <ranges>

int main(){
    constexpr std::ranges::empty_view<int> ev;
    static_assert(std::ranges::empty(ev));
    static_assert(std::ranges::size(ev) == 0);
    static_assert(std::ranges::data(ev) == nullptr);

    constexpr std::ranges::single_view<int> sv{42};
    static_assert(!std::ranges::empty(sv));
    static_assert(std::ranges::size(sv) == 1);
    static_assert(*std::ranges::data(sv) == 42);
    return 0;
}