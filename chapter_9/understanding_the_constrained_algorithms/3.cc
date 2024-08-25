#include <ranges>
#include <vector>

struct Item
{
   int         id;
   std::string name;
   double      price;
};

int main(){
    namespace rv = std::ranges::views;

    std::vector<Item> items{
        {1, "pen", 5.49},
        {2, "ruler", 3.99},
        {3, "pensil case", 12.50}
    };

    std::vector<Item> copies;

    std::ranges::copy_if(
        items, 
        std::back_inserter(copies),
        [](Item const& i) {return i.name[0] == 'p'; });

    copies.clear();

    std::ranges::copy_if(
        items, 
        std::back_inserter(copies),
        [](std::string const& name) {return name[0] == 'p'; },
        &Item::name);

    copies.clear();

    std::vector<std::string> names;
    std::ranges::copy_if(
        items | rv::transform(&Item::name),
        std::back_inserter(names),
        [](std::string const& name) {return name[0] == 'p'; });

    return 0;
}