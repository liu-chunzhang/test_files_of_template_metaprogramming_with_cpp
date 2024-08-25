template <typename T>
struct is_floating_point
{
    static const bool value = false;
};

template <>
struct is_floating_point<float>
{
    static const bool value = true;
};

template <>
struct is_floating_point<double>
{
    static const bool value = true;
};

template <>
struct is_floating_point<long double>
{
    static const bool value = true;
};

int main(){
    static_assert(is_floating_point<float>::value);
    static_assert(is_floating_point<double>::value);
    static_assert(is_floating_point<long double>::value);
    static_assert(!is_floating_point<int>::value);
    static_assert(!is_floating_point<bool>::value);
    return 0;
}