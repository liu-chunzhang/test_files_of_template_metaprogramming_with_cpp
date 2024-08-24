template <typename T>
   struct foo
   {
      void f() {}
      void g() {}
   };

int main(){
    [[maybe_unused]] foo<int>* p;
    foo<int> x;
    foo<double>* q = nullptr;

    x.f();
    q->g();
    return 0;
}