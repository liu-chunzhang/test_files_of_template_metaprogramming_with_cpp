struct A { };
struct B { };
struct C { };

template<typename... Bases>
struct X : public Bases...
{
    X(Bases const & ... args) : Bases(args)...
    { }
};

int main(){
    A a;
    B b;
    C c;
    X x(a,b,c) ;
    return 0;
}