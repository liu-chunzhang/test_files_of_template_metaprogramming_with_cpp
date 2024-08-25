#include <list>
#include <vector>

int main(){
    std::vector<int>    v{ 1 , 2 , 3 } ;
    std::list<int>      l ;

    for( std::size_t i = 0 ; i < v.size() ; ++i )
        l.push_back( v[i] ) ;
    return 0;
}