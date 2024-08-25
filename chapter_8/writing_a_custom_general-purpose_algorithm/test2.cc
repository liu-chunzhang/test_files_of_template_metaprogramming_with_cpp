#include "circular_buffer.h"
#include <concepts>
#include <iterator>
#include <type_traits>
#include <vector>
#include <cassert>

template <typename Iter>
concept InputIterator = std::input_iterator<Iter>;

template <InputIterator InputIt1, InputIterator InputIt2, typename OutputIt>
requires std::is_same_v<decltype(*std::declval<InputIt1>()), decltype(*std::declval<InputIt2>())>
OutputIt flatzip(
    InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt dest)
{
    auto it1 = first1;
    auto it2 = first2;

    while (it1 != last1 && it2 != last2)
    {
        *dest++ = *it1++;
        *dest++ = *it2++;
    }

    return dest;
}

int main(){
    std::vector<int> v1 {1, 2, 3};
    std::vector<int> v2;
    std::vector<int> v3;

    flatzip(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
    assert(v3.empty());

    std::vector<double> v4{3.0, 7.2};
    std::vector<double> v5;
    flatzip(v1.begin(), v1.end(), v4.begin(), v4.end(), std::back_inserter(v5));

    return 0;
}