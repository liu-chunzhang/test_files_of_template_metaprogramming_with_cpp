template <typename T>
struct wrapper
{
    T data ;
};

int main(){
    [[maybe_unused]] decltype(wrapper<double>::data) e1;  // double

    int a = 42;
    [[maybe_unused]] decltype(wrapper<char>::data, a) e2; // int&
}