#include <iostream>

struct A {
    void execute() { std::cout << "A::execute\n" ; }
} ;

struct B {
    void execute() { std::cout << "B::execute\n" ; }
} ;

struct C {
    void execute() { std::cout << "C::execute\n" ; }
} ;

template <typename... Bases>
struct X : public Bases... {
    X( const Bases & ... args ) : Bases( args )... { }
    using B::execute ;
} ;

int main() {
    A a ;
    B b ;
    C c ;
    X x(a,b,c) ;

    x.A::execute() ;
    x.B::execute() ;
    x.C::execute() ;
    return 0 ;
}