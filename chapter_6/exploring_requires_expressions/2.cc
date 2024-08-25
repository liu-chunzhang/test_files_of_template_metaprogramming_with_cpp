#include <string>

template <typename T>
concept KVP = requires {
    typename T::key_type;
    typename T::value_type;
};

template <typename T, typename V>
struct key_value_pair
{
    using key_type = T;
    using value_type = V;

    key_type    key;
    value_type  value;
};

int main(){
    static_assert(KVP<key_value_pair<int, std::string>>);
    static_assert(!KVP<std::pair<int, std::string>>);
    return 0;
}