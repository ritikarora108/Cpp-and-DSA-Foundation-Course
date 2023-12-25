// Time Complexity: O(nlogn)
// Space Complexity: O(n)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int largestElementAfterKOperations(vector<int> &arr,int &k)
{
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    while(k--)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        pq.push(x*y);
    }
    while(pq.size()!=1)
    {
        pq.pop();
    }
    return pq.top();
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n); 
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;                // Operation: Remove 2 smallest elements and add their product to array
    cin>>k;
    cout<<"Largest Element after "<<k<<" operations: "<<largestElementAfterKOperations(arr,k);
    return 0;
}