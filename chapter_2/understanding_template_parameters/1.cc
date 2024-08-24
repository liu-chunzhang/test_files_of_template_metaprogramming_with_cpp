#include <concepts>

template <typename T>
class wrapper1 { /* ... */ };

template <typename T = int>
class wrapper2 { /* ... */ };

template <typename>
class wrapper3;

template <typename = int>
class wrapper4;

template <typename... T>
class wrapper5 { /* ... */ };

template <typename T>
concept WrappableType = std::is_trivial_v<T>;

template <WrappableType T>
class wrapper6 { /* ... */ };

template <WrappableType T = int>
class wrapper7 { /* ... */ };

template <WrappableType... T>
class wrapper8 { /* ... */ };

int main(){

    return 0;
}