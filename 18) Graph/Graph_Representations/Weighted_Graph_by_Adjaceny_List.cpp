#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int,int>>> graph; // weighted
int v; // number of vertices;
void addEdge(int src,int dest,int weight,bool bi_dir=true){
    graph[src].push_back({dest,weight});
    if(bi_dir) {
        graph[dest].push_back({src,weight});
    }
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" : ";
        for(auto j:graph[i])
        {
            cout<<"("<<j.first<<","<<j.second<<")"<<"->";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>v;
    graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int source;
        int destination;
        int weight;
        cin>>source>>destination>>weight;
        addEdge(source,destination,weight);
    }
    display();
}