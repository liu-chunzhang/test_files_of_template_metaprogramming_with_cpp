template <typename... Args>
void make_it(Args... args)
{
}

int main(){
    make_it(42);
    make_it(42, 'a');
    return 0;
}