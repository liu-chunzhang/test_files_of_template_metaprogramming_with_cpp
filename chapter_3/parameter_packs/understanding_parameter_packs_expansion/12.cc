template <typename... T>
struct alignment1
{
    alignas(T...) char a;
};

template <int... args>
struct alignment2
{
    alignas(args...) char a;
};

int main(){
    alignment1<int, double> al1;
    al1.a = 'a';

    alignment2<1, 4, 8> al2; // error with VC++?
    al2.a = 'b';
    return 0;
}