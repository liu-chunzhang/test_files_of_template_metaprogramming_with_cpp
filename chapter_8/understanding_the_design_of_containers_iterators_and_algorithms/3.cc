#include <iostream>
#include <iterator>
#include <vector>

int main(){
    std::vector<int>    v{ 1 , 2 , 3 , 4 , 5 } ;

    // prints 1 2 3 4 5
    std::copy( v.begin() , v.end() , std::ostream_iterator<int>( std::cout , " " ) ) ;

    // prints 5 4 3 2 1
    std::copy( v.rbegin() , v.rend() , std::ostream_iterator<int>( std::cout , " " ) ) ;
    return 0;
}