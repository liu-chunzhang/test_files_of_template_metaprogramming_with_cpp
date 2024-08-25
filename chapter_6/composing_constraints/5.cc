#include <type_traits>

template <typename T>
concept A = std::is_integral_v<T>;

template <typename T>
concept B = std::is_floating_point_v<T>;

// disjunctions
template <typename T>
requires A<T> || B<T>
void f() {}

template <typename T>
requires (A<T> || B<T>)
void f() {}

template <typename T>
requires A<T> && (!A<T> || B<T>)
void f() {}

// logical operators
template <typename T>
requires (!(A<T> || B<T>))
void f() {}

template <typename T>
requires (static_cast<bool>(A<T> || B<T>))
void f() {}

int main(){
    int a = 3 ;
    double b = 4.0 ;
    f<int>() ;
    return 0;
}