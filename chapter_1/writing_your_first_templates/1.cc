template <typename T>
T max(T const a, T const b)
{
    return a > b ? a : b;
}

struct foo { } ;

int main(){
    max(1, 2);        // OK, compares ints
    max(1.0, 2.0);    // OK, compares doubles

    foo f1, f2;
    max(f1, f2);      // Error, operator> not overloaded for foo
    return 0;
}
