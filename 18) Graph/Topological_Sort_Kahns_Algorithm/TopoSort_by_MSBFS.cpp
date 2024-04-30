// Technique to detect whether a graph is DAG or not:
// Apply Topological Sort, and if count of nodes in order < vertices, given graph is not a DAG

#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void addEdge(int src,int dest,bool bi_dir=true)
{
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void topologicalSort()
{
    // Kahn's Algorithm
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto neighbour:graph[i])
        {
            // i--->neighbour
            indegree[neighbour]++;
        }
    }
    unordered_set<int> vis;
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);                 // MultiSource BFS
            vis.insert(i);
        }
    }
    while(!q.empty())
    {
        auto node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto neighbour:graph[node])
        {
            if(!vis.count(neighbour))
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) {
                    q.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
}
void display()
{
    for(int i=0;i<v;i++){
        cout<<i<<" : ";
        for(auto neighbour:graph[i])
        {
            cout<<neighbour<<"->";
        }
        cout<<endl;
    }
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
        addEdge(src,dest,false);
    }
    display();
    topologicalSort();
}