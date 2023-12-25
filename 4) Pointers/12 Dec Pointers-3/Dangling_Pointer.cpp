#include<iostream>
using namespace std;
int main()
{
    int *ptr=NULL;
    //Variable goes out of scope
    {
        int x=10;
        ptr=&x;
        cout<<ptr<<endl;
        cout<<*ptr<<endl;
    }
    cout<<ptr<<endl; // ptr pointing to such memory location,
    cout<<*ptr<<endl; // which is not valid.

    //De-allocation of memory
    int *p=(int *)malloc(sizeof(int));
    cout<<p<<endl;
    free(p);
    cout<<p<<endl;

    int *q=new int;
    cout<<q<<endl;
    delete q;
    cout<<q<<endl;
    return 0;
}