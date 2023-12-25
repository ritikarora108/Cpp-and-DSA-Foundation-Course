// Time Complexity: O(nlogn)
#include<iostream>
#include<vector>
using namespace std;
void maxHeapify(vector<int> &arr,int size,int idx)
{
    int curr=idx;
    if(curr*2+1 >= size) return;
    int leftChild=2*curr+1;
    int rightChild=2*curr+2;
    int maxChild=leftChild;
    if(rightChild<size && arr[rightChild]>arr[leftChild]) maxChild=rightChild;

    if(arr[curr]>=arr[maxChild]) return;
    swap(arr[curr],arr[maxChild]);
    curr=maxChild;
    maxHeapify(arr,size,curr);
}
void remove(vector<int> &arr,int &size)
{
    swap(arr[0],arr[size-1]);
    size--;
    maxHeapify(arr,size,0);
}
void heapSort(vector<int> &arr)
{
    int size=arr.size();
    // 1) Heapify all parent nodes into maxHeap
    for(int i=(size)/2-1;i>=0;i--)
    {
        maxHeapify(arr,size,i);
    } 
    // Keep deleting elements from maxHeap n times
    for(int i=0;i<arr.size();i++)
    {
        remove(arr,size);
    }
}
int main()
{
    int n;
    cin>>n; // 7
    vector<int> arr(n); // 60,10,80,50,5,20,70
    for(int i=0;i<n;i++) cin>>arr[i];
    heapSort(arr);
    cout<<"After HeapSort, array would look like: "<<endl;
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";  // 5 10 20 50 60 70 80
    return 0;
}