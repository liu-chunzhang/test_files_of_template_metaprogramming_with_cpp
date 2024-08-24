template <typename T>
T step_it(T value)
{
    return value+1;
}

template <typename... T>
int sum(T... args)
{
    return (... + args);
}

template <typename... T>
void captures(T... args)
{
    auto l = [args...]{ return sum(step_it(args)...); };
    auto s = l();
}

int main(){
    captures(1, 2, 3, 4);
    return 0;
}