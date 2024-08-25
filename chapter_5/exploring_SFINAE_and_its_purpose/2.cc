#include <string>

template <typename T>
void increment(T& val) { val++; }

int main(){
    int a = 42;
    increment(a);  // OK

    std::string s{ "42" };
    increment(s);  // error
    return 0;
}