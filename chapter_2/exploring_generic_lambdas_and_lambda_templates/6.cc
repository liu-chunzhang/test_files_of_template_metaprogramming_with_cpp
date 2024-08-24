#include <functional>
#include <iostream>

int main(){
    std::function<int(int)> factorial;
    factorial = [&factorial](int const n) {
        if (n < 2) return 1;
        else return n * factorial(n - 1);
    };

    std::cout << factorial(5) << '\n';
    return 0;
}