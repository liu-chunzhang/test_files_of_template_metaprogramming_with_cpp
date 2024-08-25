struct attack 
{ 
    int value; 
};

struct defence
{
    int value;
};

void increment(attack& a) { a.value++; }
void increment(defence& d) { d.value++; }

int main(){
    attack a{ 42 };
    defence d{ 50 };
    
    increment(a);
    increment(d);
    return 0;
}