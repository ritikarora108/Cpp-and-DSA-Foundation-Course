// Time Complexity of both Union and find is : O(log*n)  -> Inverse Ackermann Function
// Tc represents number of times logn... applied to make the value<=1
// Example : log*(2^16)=4 ;   2^16->16->4->2->1
#include<iostream>
#include<vector>
using namespace std;
int find(int x,vector<int> &parent)
{
    // This method return which group/cluster x belongs to
    return parent[x] = (parent[x]==x) ? x : find(parent[x],parent); // Path compression step
}
void Union(int a,int b,vector<int> &parent,vector<int> &rank)
{
    a=find(a,parent);
    b=find(b,parent);
    if(rank[a]>=rank[b])
    {
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }
}
int main()
{
    int n,m;
    // n-> no. of elements, m->no. of queries
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    while(m--)
    {
        string str;
        cin>>str;
        if(str=="union")
        {
            int x,y;
            cin>>x>>y;
            Union(x,y,parent,rank);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x,parent)<<endl;
        }
    }
}