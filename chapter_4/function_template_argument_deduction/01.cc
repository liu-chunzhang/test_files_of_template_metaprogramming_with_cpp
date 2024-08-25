#include <iostream>

template <typename T>
void process(T arg)
{
    std::cout << "process " << arg << '\n';
}

int main() {
    process(42) ;
    process<int>(42) ;
    process<short>(42) ;
    return 0 ;
}
