template <typename T>
class wrapper
{
public:
    wrapper(T const v) :value(v)
    {}

    T const& get() const { return value; }

    template <typename U>
    U as() const
    {
        return static_cast<U>(value);
    }
private:
    T value;
};

int main(){
    wrapper<double> a(42.0);
    auto d = a.get();       // double
    auto n = a.as<int>();   // int
    return 0;
}