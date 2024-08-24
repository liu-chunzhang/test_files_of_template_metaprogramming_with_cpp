template <typename T>
class foo
{
    struct bar {};

    T f(bar const arg)
    {
        return {};
    }
};

template int foo<int>::f(foo<int>::bar);

int main(){

    return 0;
}