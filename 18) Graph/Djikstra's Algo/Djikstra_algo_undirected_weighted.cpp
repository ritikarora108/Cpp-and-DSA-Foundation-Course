// Time Complexity : O((V+E)logV)

#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<list<pp>> graph;
int v;
void djikstra(int node)
{
    vector<int> dist(v,INT_MAX);
    dist[node]=0;
    vector<int> via(v);
    unordered_set<int> vis;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({0,node});
    via[node]=0;
    while(!pq.empty())  // O((V+E)logV)
    {
        auto curr=pq.top();
        pq.pop();
        if(vis.count(curr.second)) continue;
        vis.insert(curr.second);
        for(auto neighbours:graph[curr.second])
        {
            if(!vis.count(neighbours.first) && dist[neighbours.first]>curr.first+neighbours.second)
            {
                dist[neighbours.first]=curr.first+neighbours.second;
                via[neighbours.first]=curr.second;
                pq.push({dist[neighbours.first],neighbours.first});
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<dist[i]<<" "<<via[i]<<endl;
    }   
    return;
}
int main()
{
    cin>>v;
    graph.resize(v,list<pp>());
    int e;
    cin>>e;
    while(e--)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        graph[src].push_back({dest,weight});         // undirected Weighted Graph
        graph[dest].push_back({src,weight});
    }
    int node;
    cin>>node;
    djikstra(node);
    return 0;
}