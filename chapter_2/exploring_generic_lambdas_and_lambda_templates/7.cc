#include <iostream>

int main(){
    auto factorial = [](auto f, int const n) {
         if (n < 2) return 1;
         else return n * f(f, n - 1);
      };

    std::cout << factorial(factorial, 5) << '\n';
    return 0;
}