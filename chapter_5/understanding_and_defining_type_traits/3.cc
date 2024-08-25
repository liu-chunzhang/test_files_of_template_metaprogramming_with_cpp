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

int main(){
    widget w{ 1, "one" };
    w.write(std::cout);

    gadget g{ 2, "two" };
    std::cout << g;
    return 0;
}