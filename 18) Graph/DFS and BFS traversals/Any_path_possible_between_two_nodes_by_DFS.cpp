// Time Complexity : O(V+E)
// Space COmplexity : O(V) , call stack

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int v;
unordered_set<int> s;
void addEdge(int src,int dest,bool bi_dir=true)
{
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
bool dfs(int start,int end)
{
    if(start==end) return true;
    s.insert(start);
    for(auto neighbour:graph[start])
    {
        if(s.count(neighbour)) continue;
        if(dfs(neighbour,end)) return true;
    }
    return false;
}
bool anyPath(int node1,int node2)
{
    return dfs(node1,node2);
}
int main()
{
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--)
    {
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
    }
    s.clear();
    int node1,node2;
    cin>>node1>>node2;
    cout<<"Is there any path from "<<node1<<" to "<<node2<<" ? "<<endl;
    if(anyPath(node1,node2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}