#include<iostream>
using namespace std;
int main()
{
    int *ptr=NULL; //   Null pointer
    int *p1=0; // 0 is mostly special reserved memory address
    //int *p2='\0'; (error-1 or warning-0)
    cout<<ptr<<endl;
    cout<<p1<<endl;
    //cout<<p2<<endl;

    //Runtime error can occur while de-refencing a null pointer
    //cout<<*ptr<<endl; //Segmentation Fault
}