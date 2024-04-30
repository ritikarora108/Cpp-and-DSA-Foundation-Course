#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph; // unweighted
int v; // number of vertices;
void addEdge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" : ";
        for(auto j:graph[i])
        {
            cout<<j<<"->";
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
    while(e--){
        int source;
        int destination;
        cin>>source>>destination;
        addEdge(source,destination);
    }
    display();
}