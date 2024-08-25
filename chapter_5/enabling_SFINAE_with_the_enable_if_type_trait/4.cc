#include <iostream>
#include <type_traits>

template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
struct integral_wrapper
{
    T value;
};

template <typename T, typename = typename std::enable_if_t<std::is_floating_point_v<T>>>
struct floating_wrapper
{
    T value;
};

int main(){

    integral_wrapper w1{ 42 };   // OK

    #ifdef CHANGED
    integral_wrapper w2{ 42.0 }; // error
    integral_wrapper w3{ "42" }; // error
    #endif // CHANGED 

    #ifdef CHANGED
    floating_wrapper w4{ 42 };   // error
    #endif // CHANGED 

    floating_wrapper w5{ 42.0 }; // OK

    #ifdef CHANGED
    floating_wrapper w6{ "42" }; // error
    #endif // CHANGED 
    
    return 0;
}