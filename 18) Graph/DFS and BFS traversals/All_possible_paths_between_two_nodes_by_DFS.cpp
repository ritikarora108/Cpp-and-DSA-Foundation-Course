#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int v;
unordered_set<int> s;
vector<vector<int>> allPaths;
void addEdge(int src,int dest,bool bi_dir=true)
{
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void dfs(int start,int end,vector<int> &possiblePath)
{
    if(start==end) {
        possiblePath.push_back(start);
        allPaths.push_back(possiblePath);
        possiblePath.pop_back();
        return ;
    }
    s.insert(start);
    possiblePath.push_back(start);
    for(auto neighbour:graph[start])
    {
        if(s.count(neighbour)) continue;
        dfs(neighbour,end,possiblePath);
    }
    s.erase(start);
    possiblePath.pop_back();
    return ;
}
void allPossiblePaths(int node1,int node2)
{
    vector<int> possiblePath;
    dfs(node1,node2,possiblePath);
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
    cout<<"All possible pathsfrom "<<node1<<" to "<<node2<<" : "<<endl;
    allPossiblePaths(node1,node2);
    for(auto onePath:allPaths)
    {
        for(auto j:onePath)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}