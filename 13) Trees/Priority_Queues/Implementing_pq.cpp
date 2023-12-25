#include<iostream>
#include<vector>
using namespace std;
class priority_queue{
    vector<int> maxHeap;
    int currSize;
    public:
    priority_queue()
    {
        maxHeap.clear();
        currSize=0;
    }
    int size()
    {
        return currSize;
    }
    bool empty()
    {
        return currSize==0;
    }
    void push(int x)
    {
        insert(maxHeap,currSize,x);
    }
    void pop()
    {
        if(currSize==0) cout<<"SEG"<<endl;
        remove(maxHeap,currSize);
    }
    int top()
    {
        if(currSize==0) return INT_MIN;
        return maxHeap[0];
    }
    void insert(vector<int> &maxHeap,int &currSize,int &x)
    {
        maxHeap.push_back(x);
        currSize++;
        int i=currSize-1;
        while(i!=0)
        {
            if(maxHeap[i]>=maxHeap[(i-1)/2]) 
            {
                swap(maxHeap[i],maxHeap[(i-1)/2]);
                i=(i-1)/2;
            }
            else return;
        }
    }
    void remove(vector<int> &maxHeap,int &currSize)
    {
        swap(maxHeap[0],maxHeap[currSize-1]);
        currSize--;
        int curr=0;
        while(2*curr+1<currSize)
        {
            int left=2*curr+1;
            int right=2*curr+2;
            int maxi=left;
            if(right<currSize && maxHeap[right]>=maxHeap[maxi]) maxi=right;

            if(maxHeap[curr]>=maxHeap[maxi]) return;
            swap(maxHeap[curr],maxHeap[maxi]);
            curr=maxi;
        }
    }
};
int main()
{
    priority_queue pq;
    pq.push(1);
    pq.push(2);
    pq.push(0);
    pq.push(-8);
    pq.push(-7);
    pq.push(4);
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
}