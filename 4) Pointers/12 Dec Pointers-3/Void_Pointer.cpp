//Void Pointer or Generic Pointer
// Can point to any data type (generic)
#include<iostream>
using namespace std;
int main()
{
    int x=10;
    float f=6.8;
    void *ptr=&f;
    cout<<ptr<<endl;
    ptr=&x;
    //cout<<*ptr<<endl;// Void pointers can't be de-refernced
    cout<<ptr<<endl;

    int *integer_pointer = (int *)ptr; // Explicit-Type Casting
    cout<<integer_pointer<<" "<<*integer_pointer<<endl;
    return 0;
}