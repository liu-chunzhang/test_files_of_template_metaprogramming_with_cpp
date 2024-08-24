namespace ns
{
   template <typename T>
   T add(T const a, T const b)
   {
      return a + b;
   }

   template int add(int, int);          // [1]
}

template double ns::add(double, double);         // [2]

int main(){

    return 0;
}