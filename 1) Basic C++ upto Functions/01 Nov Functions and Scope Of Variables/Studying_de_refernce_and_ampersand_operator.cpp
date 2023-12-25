#include<iostream>
using namespace std;
int main()
{
    int p=5;
    int *q=&p;
    cout<<p<<endl; //5
    cout<<&p<<endl; //address of p
   // cout<<*p<<endl; // jis variable ka address 5 hai us variable value print krega (can generate error)
    cout<<q<<endl; // address of p
    cout<<&q<<endl; // address of q
    cout<<*q<<endl; // 5
    return 0;
}