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
bool bfs(int start,unordered_set<int> &vis,vector<int> &parent)
{
    queue<int> q;
    q.push(start);
    vis.insert(start);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto neighbour:graph[node])
        {
            if(vis.count(neighbour))
            {
                if(neighbour!=parent[node])
                {
                    return true;
                }
            }
            else{
                q.push(neighbour);
                vis.insert(neighbour);
                parent[neighbour]=node;
            }
        }
    }
    return false;
}
bool has_cycle()
{
    unordered_set<int> vis;
    vector<int> parent(v,-1);
    for(int i=0;i<v;i++)
    {
        if(!vis.count(i))
        {
            if(bfs(i,vis,parent)) {
                return true;
            }
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