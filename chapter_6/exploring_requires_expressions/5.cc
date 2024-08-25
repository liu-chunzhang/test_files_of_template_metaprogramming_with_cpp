#include <concepts>

template <typename T>
concept timer = requires(T t)
{
    {t.start()} -> std::same_as<void>;
    {t.stop()} -> std::convertible_to<long long>;
};

struct timerA
{
    void start() {}
    long long stop() { return 0; }
};

struct timerB
{
    void start() {}
    int stop() { return 0; }
};

struct timerC
{
    void start() {}
    void stop() {}
    long long getTicks() { return 0; }
};

int main(){
    static_assert(timer<timerA>);
    static_assert(timer<timerB>);
    static_assert(!timer<timerC>);
    return 0;
}
