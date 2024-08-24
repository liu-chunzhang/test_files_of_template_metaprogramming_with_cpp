template <typename T>
struct foo
{
    void f() {}
    void g() { int a = "42"; }
};

int main(){
    foo<int>    x ;
    return 0; 
}