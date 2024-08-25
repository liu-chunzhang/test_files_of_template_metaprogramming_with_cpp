#include <memory>

struct building {};

int main(){
    building *b = new building();

    std::shared_ptr<building> p1{ b };
    std::shared_ptr<building> p2{ b }; // bad
    return 0;
}