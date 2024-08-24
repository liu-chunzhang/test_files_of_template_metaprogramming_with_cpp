template <typename T>
class composition
{
public:
    T add(T const a, T const b)
    {
        return a + b;
    }
};

int main(){
    composition<int> c;
    c.add(41, 21);
    return 0;
}