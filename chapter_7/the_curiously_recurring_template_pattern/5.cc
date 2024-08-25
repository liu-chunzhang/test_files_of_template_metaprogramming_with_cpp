#include <iostream>

struct knight
{
    void step_forth()
    {
        std::cout << "knight moves forward\n";
    }

    void step_back()
    {
        std::cout << "knight moves back\n";
    }
};

struct mage
{
    void step_forth()
    {
        std::cout << "mage moves forward\n";
    }

    void step_back()
    {
        std::cout << "mage moves back\n";
    }
};

template <typename T>
void advance(T& t, size_t steps)
{
    while (steps--)
        t.step_forth();
}

template <typename T>
void retreat(T& t, size_t steps)
{
    while (steps--)
        t.step_back();
}

int main(){
    knight k;
    advance(k, 3);
    retreat(k, 2);

    mage m;
    advance(m, 5);
    retreat(m, 3);
    return 0;
}