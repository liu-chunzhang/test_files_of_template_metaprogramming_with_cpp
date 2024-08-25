#include "circular_buffer.h"

template <typename InputIt1, typename InputIt2, typename OutputIt>
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
    circular_buffer<int, 4> a({1, 2, 3, 4});
    circular_buffer<int, 3> b({5, 6, 7});
    circular_buffer<int, 8> c(0);

    flatzip(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    std::vector<int> v;
    for (auto e : c)
    {
        v.push_back(e);
    }
    assert(v == std::vector<int>({ 1, 5, 2, 6, 3, 7, 0, 0 }));
    return 0;
}