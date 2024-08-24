namespace ns{
    template <typename T>
    struct wrapper
    {
        T value;
    };

    template struct wrapper<int>;       // [1]
}

template struct ns::wrapper<double>;    // [2]

int main(){

    return 0;
}