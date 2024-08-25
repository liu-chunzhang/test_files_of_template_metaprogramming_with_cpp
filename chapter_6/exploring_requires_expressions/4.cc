template <typename T>
void f(T) noexcept {}

template <typename T>
void g(T) {}

template <typename F, typename ... T>
concept NonThrowing = requires(F && func, T ... t)
{
    {func(t...)} noexcept;
};

template <typename F, typename ... T> 
    requires NonThrowing<F, T...>
void invoke(F&& func, T... t)
{
    func(t...);
}  

int main(){
    invoke( f<int> , 42 ) ;
    invoke( g<int> , 42 ) ; // error
    return 0;
}