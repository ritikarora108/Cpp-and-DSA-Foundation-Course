// Time Complexity: O((k-1)logn)
#include<iostream>
#include<vector>
using namespace std;
void minHeapify(vector<int> &v,int size,int i)
{
    int n=size;
    while(2*i+1<n)
    {
        int left=2*i+1;
        int right=2*i+2;
        int mini=left;
        if(right<n && v[mini]>v[right])  mini=right;
        if(v[i]<=v[mini]) return;
        swap(v[i],v[mini]);
        i=mini; 
    }
}
void remove(vector<int> &v,int &size)
{
    swap(v[0],v[size-1]);
    size--;
    minHeapify(v,size,0);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n); //6
    for(int i=0;i<n;i++) cin>>v[i];  // 7,10,4,3,20,15
    int size=v.size();
    for(int i=n/2-1;i>=0;i--) minHeapify(v,size,i);
    int k;
    cin>>k;
    while(--k)
    {
        remove(v,size);
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }
    cout<<"kth smallest element: "<<v[0]<<endl;
}