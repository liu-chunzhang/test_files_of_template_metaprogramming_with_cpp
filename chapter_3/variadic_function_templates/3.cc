#include <iostream>

int min(int a, int b)
{
    return a < b ? a : b;
}

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

int min(int a, int b, int c, int d)
{
    return min(a, min(b, min(c, d)));
}

int min(int a, int b, int c, int d, int e)
{
    return min(a, min(b, min(c, min(d, e))));
}

int main(){
    int a , b , c , d , e ;
    std::cin >> a >> b >> c >> d >> e ;
    std::cout << min( a , b , c , d , e ) << '\n';
    return 0;
}