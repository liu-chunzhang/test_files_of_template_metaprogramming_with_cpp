#include <algorithm>
#include <array>
#include <cassert>
#include <ranges>
#include <vector>

int main(){
    // sorts a vector
    std::vector<int>    v{ 1 , 5 , 3 , 2 , 4 } ;
    std::ranges::sort( v ) ;

    // counts even numbers in an array
    std::array<int,5>   a{ 1 , 5 , 3 , 2 , 4 } ;
    auto even = std::ranges::count_if( a , []( const int n ){ return n % 2 == 0 ; } ) ;
    assert(even == 2);
    return 0;
}