#include <iterator>
#include <vector>

template <typename T>
struct range_t
{
    template <typename Iter>
    range_t(Iter first, Iter last)
    {
        std::copy(first, last, std::back_inserter(data));
    }
private:
    std::vector<T> data;
};

#ifndef CHANGED 
template <typename Iter>
range_t(Iter first, Iter last) -> range_t<typename std::iterator_traits<Iter>::value_type>;
#endif // CHANGED

int main() {
    int arr[] = { 1,2,3,4,5 };
    range_t r(std::begin(arr), std::end(arr));
    return 0 ;
}