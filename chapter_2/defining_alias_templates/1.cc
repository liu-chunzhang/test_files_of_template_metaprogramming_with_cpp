#include <string>
#include <vector>

typedef int index_t;
typedef std::vector<std::pair<int, std::string>> NameValueList;
typedef int (*fn_ptr)(int, char);

template <typename T>
struct foo
{
    typedef T value_type ;
};

int main(){

    return 0;
}