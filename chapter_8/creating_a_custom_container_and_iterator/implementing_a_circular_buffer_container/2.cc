#include <array>
#include <cassert>
#include <stdexcept>

template <typename T, std::size_t N>
requires(N > 0)
class circular_buffer
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = value_type const&;

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

    constexpr size_type size() const noexcept { return size_; }
    constexpr size_type capacity() const noexcept { return N; }
    constexpr bool empty() const noexcept { return size_ == 0; }
    constexpr bool full() const noexcept { return size_ == N; }
    constexpr void clear() noexcept { size_ = 0; head_ = 0; tail_ = 0; };

    constexpr reference operator[](size_type const pos)
    {
        return data_[(head_ + pos) % N];
    }

    constexpr const_reference operator[](size_type const pos) const
    {
        return data_[(head_ + pos) % N];
    }

    constexpr reference at(size_type const pos)
    {
        if (pos < size_)
        return data_[(head_ + pos) % N];

        throw std::out_of_range("Index is out of range");
    }

    constexpr const_reference at(size_type const pos) const
    {
        if (pos < size_)
        return data_[(head_ + pos) % N];

        throw std::out_of_range("Index is out of range");
    }

    constexpr reference front()
    {
        if (size_ > 0) return data_[head_];
        throw std::logic_error("Buffer is empty");
    }

    constexpr const_reference front() const
    {
        if (size_ > 0) return data_[head_];
        throw std::logic_error("Buffer is empty");
    }

    constexpr reference back()
    {
        if (size_ > 0) return data_[tail_];
        throw std::logic_error("Buffer is empty");
    }

    constexpr const_reference back() const
    {
        if (size_ > 0) return data_[tail_];
        throw std::logic_error("Buffer is empty");
    }

    constexpr void push_back(T const& value)
    {
        if (empty())
        {
        data_[tail_] = value;
        size_++;
        }
        else if (!full())
        {
        data_[++tail_] = value;
        size_++;
        }
        else
        {
        head_ = (head_ + 1) % N;
        tail_ = (tail_ + 1) % N;
        data_[tail_] = value;
        }
    }

    constexpr void push_back(T&& value)
    {
        if (empty())
        {
        data_[tail_] = value;
        size_++;
        }
        else if (!full())
        {
        data_[++tail_] = std::move(value);
        size_++;
        }
        else
        {
        head_ = (head_ + 1) % N;
        tail_ = (tail_ + 1) % N;
        data_[tail_] = std::move(value);
        }
    }

    constexpr T pop_front()
    {
        if (empty()) throw std::logic_error("Buffer is empty");

        size_type index = head_;

        head_ = (head_ + 1) % N;
        size_--;

        return data_[index];
    }

private:
    std::array<value_type, N> data_;
    size_type                 head_ = 0;
    size_type                 tail_ = 0;
    size_type                 size_ = 0;
};

int main(){
    circular_buffer<int, 4> b({ 1, 2, 3, 4 });

    assert(b.size() == 4);
    assert(b[0] == 1);
    assert(b[1] == 2);
    assert(b[2] == 3);
    assert(b[3] == 4);

    b.push_back(5);
    assert(b.size() == 4);
    assert(b[0] == 2);
    assert(b[1] == 3);
    assert(b[2] == 4);
    assert(b[3] == 5);

    b.push_back(6);
    assert(b.size() == 4);
    assert(b[0] == 3);
    assert(b[1] == 4);
    assert(b[2] == 5);
    assert(b[3] == 6);

    b.pop_front();
    assert(b.size() == 3);
    assert(b[0] == 4);
    assert(b[1] == 5);
    assert(b[2] == 6);
    return 0;
}