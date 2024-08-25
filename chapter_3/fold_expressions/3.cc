#include <vector>

template<typename T, typename... Args>
void push_back_many(std::vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}

int main(){
    std::vector<int> v;
    push_back_many(v, 1, 2, 3, 4, 5);
    return 0;
}
