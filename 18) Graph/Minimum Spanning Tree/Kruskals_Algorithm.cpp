// Time complexity : O(ElogE + Vlog*V)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
    int src;
    int dest;
    int wt;
};
class Dsu {
public:
    ll v;
    vector<ll> parent, size;
    Dsu(ll n) {
        v=n;
        parent.resize(v + 1);
        size.resize(v + 1, 1);
        for (int i = 0 ; i <= v ; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        return parent[node] = (parent[node]==node) ? node : find(parent[node]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (size[a] >= size[b]) {
            parent[b] = a;
            size[a] += size[b];
        }
        else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};
bool cmp(Edge &a,Edge &b)
{
    return a.wt<=b.wt;
}
int kruskals(int n,vector<Edge> &edges)
{

    sort(edges.begin(),edges.end(),cmp);
    int e=edges.size();
    int v_count=0;
    int total_weight=0;
    Dsu dsu(n);
    for(int i=0;i<e;i++)
    {
        if(dsu.find(edges[i].src)!=dsu.find(edges[i].dest))
        {
            dsu.Union(edges[i].src,edges[i].dest);
            v_count++;
            total_weight+=edges[i].wt;
        }
        if(v_count==n-1) break;
    }
    return total_weight;
}
int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<Edge> edges(e);
    for(int i=0;i<e;i++)
    {
        cin>>edges[i].src;
        cin>>edges[i].dest;
        cin>>edges[i].wt;
    }
    cout<<kruskals(n,edges)<<endl;
    return 0;
}