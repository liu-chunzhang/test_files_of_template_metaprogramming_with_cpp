
template<typename... Ts>
void process(Ts&&... ts) {}

int main() {
    process(1);              // int
    process(1, 2, 3);        // int
    process(1, 2.0, '3');    // double
    process(1, 2.0, "3");    // no error
    return 0;
}