#include <iostream>

template <size_t i>
struct int_array
{
    int data[i];
};

template<size_t i>
void process12(int_array<i>)
{ std::cout << "C<i>" << '\n'; }

int main() {

    int_array<5> ia{};
    process12(ia); // C<i>
    return 0 ;
}
