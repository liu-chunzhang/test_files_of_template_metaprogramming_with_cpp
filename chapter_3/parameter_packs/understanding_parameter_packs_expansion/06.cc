template <typename T>
T step_it(T value)
{
    return value+1;
}

template <typename... T>
void brace_enclosed(T... args)
{
    int arr1[sizeof...(args) + 1] = {args..., 0};    // 1,2,3,4,0
    int arr2[sizeof...(args)] = { step_it(args)... };// 2,3,4,5
}

int main(){
    brace_enclosed(1, 2, 3, 4);
    return 0;
}