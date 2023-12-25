#include<iostream>
using namespace std;
int check_pair_sum_exist(int arr[],int n,int x)
{
    int p=0;
    int q=n-1;
    while(p<q)
    {
        if(arr[p]+arr[q]==x) return 1;
        else if(arr[p]+arr[q]<x) p++;
        else q--;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int x;
    cin>>x;
    if(check_pair_sum_exist(arr,n,x)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}