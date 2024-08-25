#include <list>
#include <set>
#include <vector>

int main(){
    std::vector<int>    v{ 1 , 2 , 3 } ;

    // copy vector to vector
    std::vector<int>    vc( v.size() ) ;
    std::copy( v.begin() , v.end() , vc.begin() ) ;

    // copy vector to list
    std::list<int>      l ;
    std::copy( v.begin() , v.end() , std::back_inserter( l ) ) ;

    // copy list to set
    std::set<int>       s ;
    std::copy( l.begin() , l.end() , std::inserter( s , s.begin() ) ) ;
    return 0;
}