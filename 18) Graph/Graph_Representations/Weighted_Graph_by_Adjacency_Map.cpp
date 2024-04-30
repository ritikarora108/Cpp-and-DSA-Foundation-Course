#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<unordered_map<int,int>> graph; // weighted
int v; // number of vertices;
void addEdge(int src,int dest,int weight,bool bi_dir=true){
    graph[src].insert({dest,weight});
    if(bi_dir) {
        graph[dest].insert({src,weight});
    }
}

int main()
{
    cin>>v;
    graph.resize(v,unordered_map<int,int>());
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