// Time complexity : O(V)
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;
vector<list<int>> graph;
int v;
void addEdge(int src,int dest,bool bi_dir=true)
{
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void bfs(int start,vector<int> &dist)
{
    dist[start]=0;
    queue<int> q;
    q.push(start);
    unordered_set<int> s;
    cout<<"Order of visited nodes: ";
    while(!q.empty())
    {
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        s.insert(curr);
        for(auto neighbour:graph[curr])
        {
            if(!s.count(neighbour))
            {
                q.push(neighbour);
                s.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
    cout<<endl;
    return;
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
    int node;
    cin>>node;
    vector<int> dist(v);
    bfs(node,dist);
    cout<<"Shortest path of each node from "<<node<<" is : "<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<"("<<node<<"->"<<i<<") : "<<dist[i]<<endl;
    }

    return 0;
}