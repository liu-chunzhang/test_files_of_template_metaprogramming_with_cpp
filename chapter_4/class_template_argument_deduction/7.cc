template <typename T>
struct wrapper
{
    T data;
};

#ifdef CHANGED
template <typename T>
wrapper(T) -> wrapper<T> ;
#endif // CHANGED

int main() {
    wrapper w{42} ;
    return 0 ;
}