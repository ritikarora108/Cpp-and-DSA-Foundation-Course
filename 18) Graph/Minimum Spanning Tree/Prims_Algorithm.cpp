// DS - visites set, vector<int> parent, vector<int> weight, priority_queue<pp> min

// insert the pair of {0,node} in pq
// one by one remove the root element of pq
// if the root element is already visited, continue and move on
// we mark the root visited , we store the pair in the ans , v_count++
// go to every neighbour of current element and only add those which are non-visited and have better weight proposition (update the mappings)

#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>
int prims(vector<list<pp>> &graph, int n, int node)
{
    vector<int> parent(n);
    vector<int> weight(n, INT_MAX);
    weight[node] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq; // {weight,node}
    pq.push({0, node});
    int v_count = 0;
    int ans = 0;
    unordered_set<int> vis;
    while (!pq.empty() && v_count < n)
    {
        auto curr = pq.top();
        // cout<<curr.second<<" "<<curr.first<<endl;
        pq.pop();
        if (vis.count(curr.second))
            continue;
        ans += curr.first;
        v_count++;
        vis.insert(curr.second);
        for (auto neighbour : graph[curr.second])
        {
            if (!vis.count(neighbour.first) && weight[neighbour.first] > neighbour.second)
            {
                weight[neighbour.first] = neighbour.second;
                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
            }
        }
    }
    cout << "i\tparent\tweight" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << parent[i] << "\t" << weight[i] << endl;
    }
    cout << endl;
    return ans;
}
void display(vector<list<pp>> &graph, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto j : graph[i])
        {
            cout << "(" << j.first << " , " << j.second << ")  ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<list<pp>> graph(n, list<pp>());
    int e;
    cin >> e;
    while (e--)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back({dest, wt});
        graph[dest].push_back({src, wt});
    }
    int node;
    cin >> node;
    // display(graph,n);
    cout << prims(graph, n, node) << endl;
}