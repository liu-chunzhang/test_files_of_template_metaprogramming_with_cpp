#include <array>
#include <functional>

template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer_iterator;

template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer
{
public:
      using value_type = T;
      using size_type = std::size_t;

private:
    std::array<value_type, N> data_;
    size_type                 head_ = 0;
    size_type                 tail_ = 0;
    size_type                 size_ = 0;

    friend circular_buffer_iterator<T, N>;
};

template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer_iterator
{
public:
    using value_type = T;
    using size_type = std::size_t;

private:
    std::reference_wrapper<circular_buffer<T, N>> buffer_;
    size_type              index_ = 0;
};  

int main(){
    static_assert(std::is_swappable_v<circular_buffer_iterator<int, 10>>);
    return 0;
}