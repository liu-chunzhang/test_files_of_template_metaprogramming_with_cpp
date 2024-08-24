template <typename T>
T add(T const a, T const b)
{
    return a + b;
}

class foo
{
    int value;
public:
    explicit foo(int const i) :value(i)
    { }

    explicit operator int() const { return value; }
};

#ifndef CHANGED
foo operator+(foo const a, foo const b)
{
    return foo((int)a + (int)b);
}
#endif // CHANGED

int main(){
    auto a1 = add(42, 21);
    auto a2 = add<int>(42, 21);
    auto a3 = add<>(42, 21);

    auto b = add<short>(42, 21);

    auto d1 = add(41.0, 21); // error
    auto d2 = add<double>(41.0, 21);

    auto f = add(foo(42), foo(41));
    return 0;
}