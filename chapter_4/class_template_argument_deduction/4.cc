#include <mutex>

template <typename T>
struct point_t
{
    point_t(T vx, T vy) : x(vx), y(vy) {}

private:
    T x;
    T y;
};

int main() {
    auto p = new point_t(1, 2);     // point<int> // new expression

    std::mutex mt;
    auto l = std::lock_guard(mt);   // std::lock_guard<std::mutex> // function-style cast expression

    return 0 ;
}