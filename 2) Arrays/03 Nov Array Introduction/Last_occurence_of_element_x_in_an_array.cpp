#include<iostream>
using namespace std;
int LastOccurence(int arr[],int n,int key)
{
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==key) return i;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cin>>key;
    cout<<LastOccurence(arr,n,key)<<endl;
    return 0;
}