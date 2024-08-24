template <typename T>
struct is_floating_point
{
    constexpr static bool value = false;
};

template <>
struct is_floating_point<float>
{
    constexpr static bool value = true;
};

template <>
struct is_floating_point<double>
{
    constexpr static bool value = true;
};

template <>
struct is_floating_point<long double>
{
    constexpr static bool value = true;
};

template <typename T>
inline constexpr bool is_floating_point_v = is_floating_point<T>::value;