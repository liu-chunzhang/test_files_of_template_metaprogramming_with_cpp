#include <array>

/* // Currently, there is no need to define class circular_buffer_iterator
template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer_iterator;
*/

template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = value_type const&;
    using pointer = value_type*;
    using const_pointer = value_type const*;

public:
    constexpr circular_buffer() = default;

    constexpr circular_buffer(value_type const (&values)[N]) :
        size_(N), tail_(N-1)
    {
        std::copy(std::begin(values), std::end(values), data_.begin());
    }

    constexpr circular_buffer(const_reference v):
        size_(N), tail_(N-1)
    {
        std::fill(data_.begin(), data_.end(), v);
    }

private:
    std::array<value_type, N> data_;
    size_type                 head_ = 0;
    size_type                 tail_ = 0;
    size_type                 size_ = 0;
};

int main(){
    circular_buffer<int, 1> b1 ;                        // {}
    circular_buffer<int, 3> b2( { 1 , 2 , 3 } ) ;       // { 1 , 2 , 3 }
    circular_buffer<int, 3> b3( 42 ) ;                  // { 42 , 42 , 42 }
    return 0;
}