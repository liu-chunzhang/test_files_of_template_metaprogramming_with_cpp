int main(){
    int a = 0;
    int& ra = a;
    int const c = 42;
    int volatile d = 99;

    [[maybe_unused]] decltype(ra)& e1 = a;          // int&
    [[maybe_unused]] decltype(c) const e2 = 1;      // int const
    [[maybe_unused]] decltype(d) volatile e3 = 1;   // int volatile
    return 0;
}