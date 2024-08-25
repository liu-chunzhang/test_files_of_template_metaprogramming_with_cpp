#include <memory>

struct building : std::enable_shared_from_this<building>
{
};

int main(){
    building* b = new building();

    std::shared_ptr<building> p1{ b };
    std::shared_ptr<building> p2{ b->shared_from_this()}; // OK
    return 0;
}