template <auto x>
struct foo
{ /* ... */ };

int main(){      
    [[maybe_unused]] foo<42> f1;    // foo<int>
    [[maybe_unused]] foo<42.0> f2;  // foo<double>
    foo<"42"> f3;                   // error
    return 0;
}