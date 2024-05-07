// Multisource / All pairs shortest path algorithm -> Floyyd Warshall
// (detect negative cycles when cost[node][node]<0)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    while (edges--)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;

        dist[src][dest] = wt;
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int vertex = 0; vertex < n; vertex++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][vertex] + dist[vertex][j]);
            }
        }
    }

    // for (int i = 0; i < n;i++)
    // {
    //     if(dist[i][i]<0)
    //     {
    //         cout << "Negative cycle exists" << endl;
    //         break;
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
