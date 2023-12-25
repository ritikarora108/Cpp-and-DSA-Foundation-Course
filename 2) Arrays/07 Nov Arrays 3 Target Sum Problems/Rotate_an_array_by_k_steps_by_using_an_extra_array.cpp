#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int &i:arr) cin>>i;
    int k;
    cin>>k;
    k=k%n;
    int ans[n];
    for(int i=0;i<k;i++)
    {
        ans[i]=arr[n-k+i];
    }
    for(int i=k;i<n;i++)
    {
        ans[i]=arr[i-k];
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}