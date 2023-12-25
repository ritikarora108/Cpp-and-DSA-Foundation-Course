#include<iostream>
using namespace std;
int main()
{
    int arr[5]={7,4,6,46,8};
    int (*p)[5]=&arr;

    cout<<p<<" "<<*p<<" "<<*(*p)<<endl;
    cout<<p<<" "<<*(p+1)<<" "<<*(*p+1)<<endl;
    cout<<p<<" "<<*(p+4)<<" "<<*(*p+4)<<endl;

    int a[3][3]={{6,4,7},{8,4,6},{1,6,3}};
    int (*ptr)[3]=&a[0];
    cout<<*(*(ptr+2)+1)<<endl;
}