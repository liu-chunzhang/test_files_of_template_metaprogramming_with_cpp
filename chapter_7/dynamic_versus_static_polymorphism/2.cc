#include <iostream>
#include <vector>

struct game_unit
{
    virtual void attack() = 0;
};

struct knight : game_unit
{
    void attack() override
    {
        std::cout << "draw sword\n";
    }
};

struct mage : game_unit
{
    void attack() override
    {
        std::cout << "spell magic curse\n";
    }
};

void fight(std::vector<game_unit*> const & units)
{
    for (auto unit : units)
    {
        unit->attack();
    }
}

struct knight_mage : game_unit
{
    void attack() override
    {
        std::cout << "draw magic sword\n";
    }
};

knight_mage operator+(knight const& k, mage const& m)
{
    return knight_mage{};
}

int main(){
    knight k;
    mage m;

    knight_mage km = k + m;
    km.attack();
    return 0;
}