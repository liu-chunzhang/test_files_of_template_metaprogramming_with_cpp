template <typename T>
struct control
{};

template <typename T>
struct button : public control<T>
{};

void show(button<int>* ptr)
{
    control<int>* c = ptr;
}

int main(){

    return 0; 
}