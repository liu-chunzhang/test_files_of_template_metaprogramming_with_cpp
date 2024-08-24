template <typename T = int>
class foo { /*...*/ };

template <typename T = int, typename U = double>
class bar { /*...*/ };

template <typename T = int, typename U>
class bar2 { };             // error

template <typename T = int, typename U>
void func() {}              // OK

int main(){

    return 0;
}