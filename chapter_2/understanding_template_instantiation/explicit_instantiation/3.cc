namespace ns
{
   template <typename T>
   struct wrapper
   {
      T value;
   };
}

using namespace ns ;

template struct wrapper<double> ;

int main(){

    return 0;
}