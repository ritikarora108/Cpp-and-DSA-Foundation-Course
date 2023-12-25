// Complete Binary Tree: All levels are filled completely except may be the last level,
//                       and last level has keys as left as possible.

// Height of Complete Binary Tree: logn

// Heap is a complete binary tree : exist as either MinHeap or MaxHeap
// 1-Based Indexing in Array: Root node will be at index 1
//                            Left child of a node (at i index) : 2*i
//                            Right child of a node (at i index) : 2*i+1
//                            Parent of a child node (at i) :|_ i/2 _|

#include<iostream>
using namespace std;
const int N=1e3;
void insert(int minHeap[],int &size,int x)   // Worst Case time complexity: O(logn)
{
    size++;
    minHeap[size]=x;
    int curr=size;
    while(curr!=1 && minHeap[curr] < minHeap[curr/2])
    {
        swap(minHeap[curr],minHeap[curr/2]);
        curr/=2;
    }
}
void remove(int minHeap[],int &size)   // Worst case time complexity : O(logn)
{
    swap(minHeap[1],minHeap[size]);
    size--;
    int curr=1;
    while(2*curr<=size)  // looping till curr Node has child Nodes
    {
        int leftChild=2*curr;
        int rightChild=2*curr+1;
        int minChild=leftChild;

        if(rightChild<=size && minHeap[rightChild] < minHeap[leftChild])
        {
            minChild=rightChild;
        }
        if(minHeap[curr]<minHeap[minChild]) return;

        swap(minHeap[curr],minHeap[minChild]);
        curr=minChild;
    }
}
int main()
{
    int minHeap[N]={-1,10,20,30,40,50};
    int size=5;
    cout<<"Enter the element to be inserted: ";
    int x;
    cin>>x;  // 5
    insert(minHeap,size,x);
    cout<<"After insertion, minHeap would look like: "<<endl;
    for(int i=1;i<=size;i++) cout<<minHeap[i]<<" ";
    cout<<endl;
    remove(minHeap,size);
    cout<<"After removal, minHeap would look like: "<<endl;
    for(int i=1;i<=size;i++) cout<<minHeap[i]<<" ";
    return 0;
}