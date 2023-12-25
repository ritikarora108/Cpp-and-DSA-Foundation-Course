#include<iostream>
using namespace std;
void f(int num,int k)
{
    //base case
    if(k<1) return;
    //print first k-1 multiples 
    f(num,k-1);
    //print kth multiple of num
    cout<<(num*k)<<" ";
}
int main()
{
    int num,k;
    cout<<"Enter num and k: ";
    cin>>num>>k;
    f(num,k);
    // f prints the first k multiples of num
    return 0;
}