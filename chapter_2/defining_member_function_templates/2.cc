class composition
{
public:
    template <typename T>
    T add(T const a, T const b)
    {
        return a + b;
    }
};

int main(){
    composition c;
    c.add<int>(41, 21);
    c.add(41.6, 21.3);      // My note: with deduction of template parameters, <XXX> can be omitted.
    return 0;
}