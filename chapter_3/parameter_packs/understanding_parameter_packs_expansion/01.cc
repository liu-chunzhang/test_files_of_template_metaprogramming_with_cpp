template <typename... T>
struct outer
{
    template <T... args>
    struct inner {};
};

int main(){
    [[maybe_unused]] outer<int, double, char[5]> a; 
    return 0;
}