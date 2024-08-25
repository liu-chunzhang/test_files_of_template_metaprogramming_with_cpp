#include <any>
#include <functional>
#include <iostream>

struct knight
{
    void attack() { std::cout << "draw sword\n"; }
};

struct mage
{
    void attack() { std::cout << "spell magic curse\n"; }
};

int main(){
    std::any u;

    u = knight{};
    if (u.has_value())
        std::any_cast<knight>(u).attack();

    u = mage{};
    if (u.has_value())
        std::any_cast<mage>(u).attack();
    return 0;
}