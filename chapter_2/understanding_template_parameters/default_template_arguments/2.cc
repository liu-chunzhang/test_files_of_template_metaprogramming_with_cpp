template <typename T, typename U = double>
struct foo;

template <typename T = int, typename U>
struct foo;

template <typename T, typename U>
struct foo
{
    T a;
    U b;
};

int main(){

    return 0;
}