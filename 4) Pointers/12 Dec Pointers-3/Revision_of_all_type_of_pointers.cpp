#include<iostream>
using namespace std;
int main()
{
    int *ptr; // wild pointer
    cout<<ptr<<endl;
    //cout<<*ptr<<endl;  // segmentation fault
    //can't de-reference a wild pointer

    int *p=NULL;
    int *p1=0; // 0 is specially reserved in memory
    //int *p2='\0';
    cout<<p<<endl;
    cout<<p1<<endl;
    // cout<<*p<<endl;

    //Can't de-reference a NULL POINTER

    int *ptr1=NULL;  //variable out of scope to generate a dangling pointer
    {
        int x=10;
        ptr1=&x;
        cout<<ptr1<<" "<<*ptr1<<endl;
    }
    cout<<ptr1<<" "<<*ptr1<<endl;


    //De-allocation of memory to generate a dangling pointer
    int *q=(int *)malloc(sizeof(int));
    cout<<q<<endl;
    free(q);
    cout<<q<<endl;


    int *r=new int;
    cout<<r<<endl;
    delete r;
    cout<<r<<endl;


    //void pointer (generic ; can point to any data type variable)
    void *pointer=NULL;
    int z=9;
    float j=7.5;
    pointer=&z;
    cout<<pointer<<endl;
    //cout<<*z<<endl; can't de-reference a void pointer

    pointer=&j;
    cout<<pointer<<endl;

    float *floating_pointer=(float *)pointer; //Explicitly type casted
    cout<<floating_pointer<<" "<<*floating_pointer<<endl;
    return 0;
}