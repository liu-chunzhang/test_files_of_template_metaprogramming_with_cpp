#include <list>
#include <vector>

int main(){
    std::vector<int> v{ 1,2,3,4,5 };
    auto sv = std::begin(v);
    std::advance(sv, 2);

    std::list<int> l{ 1,2,3,4,5 };
    auto sl = std::begin(l);
    std::advance(sl, 2);
    return 0;
}