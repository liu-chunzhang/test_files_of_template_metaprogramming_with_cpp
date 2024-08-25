#include <iostream>

struct widget
{
    int         id;
    std::string name;

    std::ostream& write(std::ostream& os) const
    {
        os << id << ',' << name << '\n';
        return os;
    }
};

template <typename T>
bool are_equal(T const& a, T const& b)
{
    if constexpr (std::is_floating_point_v<T>)
        return std::abs(a - b) < 0.001;
    else
        return a == b;
}

int main(){
    std::cout << are_equal(1, 1) << '\n' ;
    std::cout << are_equal(1.999998, 1.999997) << '\n' ;
    std::cout << are_equal(std::string{ "1" }, std::string{ "1" }) << '\n' ;
    std::cout << are_equal(widget{ 1, "one" }, widget{ 1, "two" }) << '\n' ;
    return 0;
}