#include<iostream>
using namespace std;
const int N=1e3;
void maxHeapifyIteratively(int arr[],int size,int idx)
{
    int curr=idx;
    while(2*curr<=size)
    {
        int leftChild=2*curr;
        int rightChild=leftChild+1;
        int maxChild=leftChild;
        if(rightChild<=size && arr[rightChild]>arr[leftChild]) maxChild=rightChild;
        if(arr[curr]>=arr[maxChild]) return;

        swap(arr[curr],arr[maxChild]);
        curr=maxChild;
    }
}
void maxHeapifyRecursively(int arr[],int size,int idx)
{   
    int curr=idx;
    if(2*curr>size) return;
    int leftChild=2*curr;
    int rightChild=2*curr+1;
    int maxChild=leftChild;
    if(rightChild<=size && arr[rightChild]>arr[leftChild]) maxChild=rightChild;
    if(arr[curr]>=arr[maxChild]) return;
    swap(arr[curr],arr[maxChild]);
    curr=maxChild;
    maxHeapifyRecursively(arr,size,curr);
}
int main()
{
    int arr[N]={-1,60,10,80,50,5,20,70};
    int size=7;
    for(int i=size/2;i>=1;i--)
    {
        maxHeapifyRecursively(arr,size,i);
    }
    cout<<"After MaxHeapifying:"<<endl;
    for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}