#include<iostream>
using namespace std;
void print(int *p)
{
    cout<<p<<" "<<*p<<endl;
}
int main()
{
    int arr[]={10,7,4,6};
    int *ptr=&arr[0];

    print(ptr);
    arr[0]++;
    print(ptr);

    *ptr++; // Right to left : *(ptr++)
    print(ptr);

    (*ptr)++;
    print(ptr);

    *++ptr;
    print(ptr);

    ++*ptr;
    print(ptr);
    return 0;

}