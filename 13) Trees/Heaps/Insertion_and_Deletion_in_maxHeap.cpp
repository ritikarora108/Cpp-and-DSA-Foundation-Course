#include<iostream>
using namespace std;
const int N=1e3;
void insert(int maxHeap[],int &size,int x)
{
    size++;
    maxHeap[size]=x;
    int curr=size;
    while(curr!=1 && maxHeap[curr] > maxHeap[curr/2])
    {
        swap(maxHeap[curr],maxHeap[curr/2]);
        curr/=2;
    }
}
void remove(int maxHeap[],int &size)
{
    swap(maxHeap[1],maxHeap[size]);
    size--;
    int curr=1;
    while(2*curr<=size)
    {
        int leftChild=2*curr;
        int rightChild=2*curr+1;
        int maxChild=leftChild;
        if(rightChild<=size && maxHeap[rightChild]> maxHeap[leftChild])
        {
            maxChild=rightChild;
        }

        if(maxHeap[curr]>maxHeap[maxChild]) return;

        swap(maxHeap[curr],maxHeap[maxChild]);
        curr=maxChild;
    }
}
int main()
{
    int maxHeap[N]={-1,60,50,40,30,20,30,10};
    int size=7;
    int x;
    cout<<"Enter the element to be inserted: ";
    cin>>x; // 100
    insert(maxHeap,size,x);
    cout<<"After insertion, the maxHeap would look like:"<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<maxHeap[i]<<" ";
    }
    cout<<endl;
    remove(maxHeap,size);
    cout<<"After removal, the maxHeap would look like: "<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<maxHeap[i]<<" ";
    }
    return 0;
}