#include <string>

int main(){
    auto l1 = [](int a) {return a + a; };           // C++11, regular lambda
    auto l2 = [](auto a) {return a + a; };          // C++14, generic lambda
    auto l3 = []<typename T>(T a) { return a + a; };// C++20, template lambda

    auto v1 = l1(42);	                            // OK
    auto v2 = l1(42.0);	                            // OK
    auto v3 = l1(std::string{ "42" });              // error

    auto v5 = l2(42);                               // OK
    auto v6 = l2(42.0);                             // OK
    auto v7 = l2(std::string{"42"});                // OK

    auto v8 = l3(42);                               // OK
    auto v9 = l3(42.0);                             // OK
    auto v10 = l3(std::string{ "42" });             // OK
    return 0;
}