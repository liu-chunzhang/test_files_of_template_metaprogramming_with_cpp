template <typename T>
struct PI
{
    static const T value;
};

template <typename T> 
const T PI<T>::value = T(3.1415926535897932385L);

template <typename T>
T sphere_volume(T const r)
{
    return 4 * PI<T>::value * r * r * r / 3;
}

int main() {
    float v1 = sphere_volume( 42.0f ) ;
    double v2 = sphere_volume( 42.0 ) ;
    return 0 ;
}