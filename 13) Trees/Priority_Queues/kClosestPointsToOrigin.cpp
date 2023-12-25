// Mannhattan Diatance between (x1,y1) and (x2,y2) is: abs(x2-x1)+abs(y2-y1)
// Time Complexity: O(nlogk)
// Space Complexity: O(k)->pq(maxHeap)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class cmp{
    public:
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.first+a.second < b.first+b.second;
    }
};
vector<pair<int,int>> kClosestPointsToOrigin(vector<pair<int,int>> &points,int &k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    int n=points.size();
    for(int i=0;i<k;i++)
    {
        pq.push(points[i]);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(points[i]);
        if(pq.size()>k) pq.pop();
    }
    vector<pair<int,int>> ans(k);
    while(!pq.empty())
    {
        ans[pq.size()-1]=pq.top();
        pq.pop();
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points[i]={x,y};
    }
    int k;
    cin>>k;
    vector<pair<int,int>> ans=kClosestPointsToOrigin(points,k);
    cout<<k<<" closest points to origin: "<<endl;
    for(auto i:ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}