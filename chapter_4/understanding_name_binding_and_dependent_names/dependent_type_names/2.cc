#include <iostream>
#include <map>

struct dictionary_traits
{
    using key_type = int;
    using map_type = std::map<key_type, std::string>;
    static constexpr int identity = 1;
};

template <typename T>
struct dictionary : T::map_type
{
    int start_key{ T::identity };
    T::key_type next_key;
};

int main(){
    dictionary<dictionary_traits> d ;
    return 0 ;
}