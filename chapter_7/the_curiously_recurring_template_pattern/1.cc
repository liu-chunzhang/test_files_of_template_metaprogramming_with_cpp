#include <iostream>
#include <vector>

template <typename T>
struct game_unit
{
    void attack()
    {
        static_cast<T*>(this)->do_attack();
    }
};

struct knight : game_unit<knight>
{
    void do_attack()
    {
        std::cout << "draw sword\n";
    }
};

struct mage : game_unit<mage>
{
    void do_attack()
    {
        std::cout << "spell magic curse\n";
    }
};

template <typename T>
void fight(std::vector<game_unit<T>*> const & units)
{
    for (auto unit : units)
    {
        unit->attack();
    }
}

int main(){
    knight k;
    mage m;

    fight<knight>({ &k });
    fight<mage>({ &m });
    return 0;
}