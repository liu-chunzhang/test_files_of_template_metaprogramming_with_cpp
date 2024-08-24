#include <string>

int main(){
    auto l1 = [](int a, int b) {return a + b; };
    auto l2 = [](auto a, auto b) {return a + b; };
    auto l3 = []<typename T, typename U>(T a, U b) { return a + b; };
    auto l4 = [](auto a, decltype(a) b) {return a + b; };

    auto v1 = l1(42, 1);	                                    // OK
    auto v2 = l1(42.0, 1.0);	                                // OK
    auto v3 = l1(std::string{ "42" }, '1');                     // error

    auto v4 = l2(42, 1);                                        // OK
    auto v5 = l2(42.0, 1);                                      // OK
    auto v6 = l2(std::string{ "42" }, '1');                     // OK
    auto v7 = l2(std::string{ "42" }, std::string{ "1" });      // OK

    auto v8 = l3(42, 1);                                        // OK
    auto v9 = l3(42.0, 1);                                      // OK
    auto v10 = l3(std::string{ "42" }, '1');                    // OK
    auto v11 = l3(std::string{ "42" }, std::string{ "42" });    // OK

    auto v12 = l4(42.0, 1);                                     // OK
    auto v13 = l4(42, 1.0);                                     // OK
    auto v14 = l4(std::string{ "42" }, '1');                    // error
    return 0;
}