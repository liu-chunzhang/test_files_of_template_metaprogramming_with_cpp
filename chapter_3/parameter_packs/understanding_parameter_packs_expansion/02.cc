template <typename... T>
struct tag {};

template <typename T, typename U, typename ... Args>
void tagger()
{
    [[maybe_unused]] tag<T, U, Args...> t1;
    [[maybe_unused]] tag<T, Args..., U> t2;
    [[maybe_unused]] tag<Args..., T, U> t3;
    [[maybe_unused]] tag<U, T, Args...> t4;
}

int main(){
    tagger<int, double, char[5], short, float>();
    return 0;
}
