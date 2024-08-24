#include <string>


int main(){
    auto l = []<typename T>(T a, T b) { return a + b; };

    auto v1 = l(42, 1);         // OK
    auto v2 = l(42.0, 1);       // error

    auto v4 = l(42.0, 1.0);     // OK
    auto v5 = l(42, false);     // error

    auto v6 = l(std::string{ "42" }, std::string{ "1" }); // OK
    auto v6 = l(std::string{ "42" }, '1');                // error
    return 0;
}