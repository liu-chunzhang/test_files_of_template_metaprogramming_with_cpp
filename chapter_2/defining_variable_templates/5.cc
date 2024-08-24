struct math_constants
{
    template<class T>
    static constexpr T PI = T(3.1415926535897932385L);
};

template <typename T>
T sphere_volume(T const r)
{
    return 4 * math_constants::PI<T> *r * r * r / 3;
}

int main() {
    float v1 = sphere_volume( 42.0f ) ;
    double v2 = sphere_volume( 42.0 ) ;
    return 0 ;
}