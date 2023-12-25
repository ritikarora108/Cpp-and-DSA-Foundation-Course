// Heapify : Arranging nodes in correct order so that they follow properties of minHeap/maxHeap.

//In 1-based indexing, last non-leaf(parent) Node is present at an index : n/2
#include<iostream>
using namespace std;
const int N=1e3;
void minheapifyIteratively(int arr[],int size,int idx)  // this function individually has TC: O(logn)
{
    int curr=idx;
    while(2*curr<=size)
    {
        int leftChild=2*curr;
        int rightChild=2*curr+1;
        int minChild=leftChild;
        if(rightChild<=size && arr[rightChild]<arr[leftChild])
        {
            minChild=rightChild;
        }
        if(arr[curr]<=arr[minChild]) return;

        swap(arr[curr],arr[minChild]);
        curr=minChild;
    }
}
void minheapifyRecursively(int arr[],int size,int idx)    
{
    int curr=idx;
    if(2*curr>size) return;      //leaf Node
    int leftChild=2*curr;
    int rightChild=2*curr+1;
    int minChild=leftChild;
    if(rightChild<=size && arr[rightChild]<arr[leftChild])
    {
        minChild=rightChild;
    }
    if(arr[curr]<arr[minChild]) return;        // Node at curr is on right position
    swap(arr[curr],arr[minChild]); 
    curr=minChild;
    minheapifyRecursively(arr,size,curr);
}
int main()
{
    int arr[N]={-1,60,10,80,50,5,20,70};
    int size=7;
    for(int i=size/2;i>=1;i--)
    {
        minheapifyRecursively(arr,size,i);
    }
    cout<<"After MinHeapifying:"<<endl;
    for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
}