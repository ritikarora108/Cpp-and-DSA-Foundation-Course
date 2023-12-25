// Time Complexity:O(nlogk)

//  Can be done by sorting or implementing a maxHeap(heapify, then removing top k-1 elements , kth largest will be at top now)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthLargestElement(vector<int> &v,int &k)
{
    int n=v.size();
    priority_queue<int,vector<int>,greater<int>> pq;  // minHeap
    for(int i=0;i<k;i++)
    {
        pq.push(v[i]);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(v[i]);
        if(pq.size()>k) pq.pop();         // Having only k elements in pq
    }
    return pq.top();
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;
    cin>>k;
    cout<<"Kth largest element: "<<kthLargestElement(v,k)<<endl;
    return 0;
}