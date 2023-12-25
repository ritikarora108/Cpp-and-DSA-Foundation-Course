#include<iostream>
using namespace std;
int f(int n)
{
    //base case
    if(n==0) return 0;

    int ans=0;
    (n&1) ? (ans=f(n-1)+n) : (ans=f(n-1)-n); // Adding odds and subtracting evens 
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int ans=f(n); // f determines the sum of natural numbers with alternate sign
    cout<<ans<<endl;
    return 0;
}