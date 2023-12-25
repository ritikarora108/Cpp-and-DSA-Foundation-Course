//Linear Search
#include<iostream>
#include<vector>
using namespace std;
//exist returns whether x is present between ith to (n-1)th index of array or not
bool exist(vector<int> &arr,int n,int i,int x)
{
    //base case
    if(i==n) return 0; //array is exhausted
    return (arr[i]==x) || exist(arr,n,i+1,x);
    //check whether x is presnt on ith index, else go further 
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int x;
    cin>>x;
    if(exist(arr,n,0,x)) cout<<"Yes, "<<x<<" is present in the array"<<endl;
    else cout<<x<<" is not present in the array"<<endl;
    return 0;
}