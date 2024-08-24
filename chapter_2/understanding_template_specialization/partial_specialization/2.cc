template <int A, int B>
struct foo {};

template <int A>
struct foo<A, A> {};

template <int A>
struct foo<A, A + 1> {}; // error

int main(){
    foo  a ;
    return 0;
}