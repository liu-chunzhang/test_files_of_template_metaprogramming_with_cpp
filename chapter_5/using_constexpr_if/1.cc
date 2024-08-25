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

struct gadget
{
    int         id;
    std::string name;

    friend std::ostream& operator <<(std::ostream& os, gadget const& o);
};

std::ostream& operator <<(std::ostream& os, gadget const& o)
{
    os << o.id << ',' << o.name << '\n';
    return os;
}

template <typename T>
struct uses_write
{
    static constexpr bool value = false;
};

template <>
struct uses_write<widget>
{
    static constexpr bool value = true;
};

template <typename T>
inline constexpr bool uses_write_v = uses_write<T>::value;

template <typename T>
void serialize(std::ostream& os, T const& value)
{
    if constexpr (uses_write_v<T>)
        value.write(os);
    else
        os << value;
}

int main(){
    widget w{ 1, "one" };
    serialize(std::cout, w);

    gadget g{ 2, "two" };
    serialize(std::cout, g);
    return 0;
}