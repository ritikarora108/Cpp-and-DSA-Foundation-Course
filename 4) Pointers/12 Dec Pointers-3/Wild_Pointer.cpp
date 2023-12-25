#include<iostream>
using namespace std;
int main()
{
    int *ptr;// declared only but not defined
    cout<<ptr<<endl;
    //cout<<*ptr<<endl; //Segmentation fault
}