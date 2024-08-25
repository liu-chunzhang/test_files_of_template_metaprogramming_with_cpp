#include <vector>

template <std::integral T>
using integral_vector = std::vector<T>;

int main(){
    integral_vector<int> v1{ 1,2,3 };           // OK
    integral_vector<double> v2 {1.0, 2.0, 3.0}; // error
    return 0;
}