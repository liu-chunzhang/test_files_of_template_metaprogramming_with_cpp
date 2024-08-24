template <typename T = int>
struct foo;

template <typename T = int> // error
struct foo {};

int main(){

    return 0;
}