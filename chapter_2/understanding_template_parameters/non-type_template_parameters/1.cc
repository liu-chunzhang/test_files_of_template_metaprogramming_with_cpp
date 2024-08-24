template <int V>
class foo1 { /*...*/ };

template <int V = 42>
class foo2 { /*...*/ };

template <int... V>
class foo3 { /*...*/ };

int main(){

    return 0;
}