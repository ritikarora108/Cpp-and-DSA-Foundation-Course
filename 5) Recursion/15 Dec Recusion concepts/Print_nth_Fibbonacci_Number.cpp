// Space Complexity : O(n)
//Time Complexity : O(2^n)
//Tree - preorder traversal : function call
// 2^0+2^1+2^2+2^3+....+2^(n-1) = (2^n)-1;
//T=((2^n)-1).(c) = O(2^n)

#include<iostream>
using namespace std;
int fib(int n)
{
    if(n==0 || n==1) return n;
    else return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl; // fib(n) prints the nth fibbonacci number.
    return 0;
}