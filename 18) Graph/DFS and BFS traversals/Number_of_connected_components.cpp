#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
int v;
vector<list<int>> graph;
void addEdge(int src,int dest,bool bi_dir=true)
{
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void display()
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<" -> ";
        for(auto j:graph[i])
        {
            cout<<j<<" , ";
        }
        cout<<endl;
    }
}
void dfs(int node,unordered_set<int> &vis)
{
    vis.insert(node);
    for(auto neighbour:graph[node])
    {
        if(!vis.count(neighbour))
        {
            dfs(neighbour,vis);
        }
    }
    return;
}
int connectedComponents()
{
    unordered_set<int> vis;
    int cnt=0;
    for(int i=0;i<v;i++)
    {
        // go to every vertex
        // if from a vertex we can initiate a dfs, then we can have one more cc
        if(!vis.count(i))
        {
            cnt++;
            dfs(i,vis);
        }
    }
    return cnt;
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
    cout<<"Number of connected components in graph : "<<connectedComponents()<<endl;
    return 0;
}