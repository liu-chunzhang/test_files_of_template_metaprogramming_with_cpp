#include <string>
#include <vector>

using index_t = int;
using NameValueList = std::vector<std::pair<int, std::string>>;
using fn_ptr = int(int, char);

template <typename T>
struct foo
{
    using value_type = T ;
};

int main(){

    return 0;
}