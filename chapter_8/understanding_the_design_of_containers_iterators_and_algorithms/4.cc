#include <iostream>
#include <vector>

int main(){
    std::vector<int>    v{ 1 , 2 , 3 , 4 , 5 } ;

    for( auto const &e : v )
        std::cout << e << ' ' ;

    int a[] = { 1 , 2 , 3 , 4 , 5 } ;
    for( auto const &e : a )
        std::cout << e << ' ' ;
    return 0;
}