#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void addEdge(int src,int dest,bool bidir=true)
{
    graph[src].push_back(dest);
    if(bidir) graph[dest].push_back(src);
}
void display()
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<" : ";
        for(auto neigh:graph[i])
        {
            cout<<neigh<<"->";
        }
        cout<<endl;
    }
}
bool dfs(int start,unordered_set<int> &vis,int parent)
{
    vis.insert(start);
    for(auto neighbour:graph[start])
    {
        if(vis.count(neighbour))
        {
            if(neighbour!=parent) {
                // cycle detected
                return true;
            }
        }
        else {
            if(dfs(neighbour,vis,start)) return true;
        }
    }
    return false;
}
bool has_cycle()
{
    unordered_set<int> vis;
    for(int i=0;i<v;i++)
    {
        if(!vis.count(i))
        {
            if(dfs(i,vis,-1)) return true;
        }
    }
    return false;
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
    display();
    cout<<has_cycle()<<endl;
}