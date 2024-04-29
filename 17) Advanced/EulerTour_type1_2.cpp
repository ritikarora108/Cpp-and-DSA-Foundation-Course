#include <bits/stdc++.h>
using namespace std;
void eulert1(vector<list<int>> &graph, int src, int parent, vector<int> &ans)
{
    ans.push_back(src);
    for (auto ngh : graph[src])
    {
        if (ngh != parent)
        {
            eulert1(graph, ngh, src, ans);
            ans.push_back(src);
        }
    }
    return;
}
void eulert2(vector<list<int>> &graph, int src, int parent, vector<int> &ans)
{
    ans.push_back(src);
    for (auto ngh : graph[src])
    {
        if (ngh != parent)
            eulert2(graph, ngh, src, ans);
    }
    ans.push_back(src);
    return;
}
int main()
{
    int vertices;
    cin >> vertices;
    vector<list<int>> graph(vertices + 1, list<int>());
    int edges;
    cin >> edges;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // rooted at 1
    vector<int> ans1;
    eulert1(graph, 1, -1, ans1);
    cout << "Euler Tour Type 1: ";
    for (auto i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Euler Tour Type 2: ";
    vector<int> ans2;
    eulert2(graph, 1, -1, ans2);
    for (auto i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
}