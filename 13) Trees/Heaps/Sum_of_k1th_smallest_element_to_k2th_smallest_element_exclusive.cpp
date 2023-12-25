// Time Complexity: O((k2-1)logn)
#include<iostream>
#include<vector>
using namespace std;
void minHeapify(vector<int> &arr,int &size,int idx)
{
    int curr=idx;
    while(2*curr+1<size)
    {
        int leftChild=2*curr+1;
        int rightChild=2*curr+2;
        int minChild=leftChild;
        if(rightChild<size && arr[rightChild]<arr[leftChild]) minChild=rightChild;

        if(arr[curr]<=arr[minChild]) return;
        swap(arr[curr],arr[minChild]);
        curr=minChild;
    }
}
int remove(vector<int> &arr,int &size)
{
    int ans=arr[0];
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(arr,size,0);
    return ans;
}
int main()
{
    int n;
    cin>>n;  // 7
    vector<int> arr(n);  
    for(int i=0;i<n;i++) cin>>arr[i];   // 20,8,22,4,12,10,14
    int k1,k2; //3,6
    cin>>k1>>k2;
    int size=arr.size();
    for(int i=n/2-1;i>=0;i--)
    {
        minHeapify(arr,size,i);
    }
    for(int i=1;i<=k1;i++)
    {
        remove(arr,size);
    }
    int sumK1toK2=0;
    for(int i=k1+1;i<k2;i++)
    {
        sumK1toK2+=remove(arr,size);
    }
    cout<<sumK1toK2<<endl;
}