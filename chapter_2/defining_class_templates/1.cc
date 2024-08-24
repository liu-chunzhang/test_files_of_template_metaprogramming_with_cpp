template <typename T>
class wrapper
{
public:
    wrapper(T const v):value(v)
    { }

    T const& get() const { return value; }
private:
    T value;
};

int main(){
    wrapper a(42);           // wraps an int
    wrapper<int> b(42);      // wraps an int
    wrapper<short> c(42);    // wraps a short
    wrapper<double> d(42.0); // wraps a double
    wrapper e("42");         // wraps a char const *
    return 0;
}