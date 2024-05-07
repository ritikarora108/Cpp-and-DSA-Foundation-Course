#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int par, vector<vector<int>> &parent, vector<list<int>> &tree)
{
    parent[node][0] = par;
    for (auto i : tree[node])
    {
        if (i != par)
        {
            dfs(i, node, parent, tree);
        }
    }
}
void kthParent_BinaryLifting(vector<list<int>> &tree, int n)
{
    int maxLevel = log2(n) + 1;
    vector<vector<int>> parent(n + 1, vector<int>(maxLevel + 1, -1));
    dfs(1, -1, parent, tree);
    // 2^0th parent is already available
    // simple dfs 2^0=1th parent is already done
    for (int i = 1; i <= maxLevel; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            int intermediate = parent[node][i - 1];
            if (intermediate != -1)
            {
                parent[node][i] = parent[intermediate][i - 1];
            }
        }
    }
    // time complexity -> NlogN
    int q;
    cin >> q;
    while (q--)
    {
        int node;
        cin >> node;
        int k;
        cin >> k;

        while (k > 0)
        {
            int level = log2(k);
            node = parent[node][level];
            k -= (1 << level);
        }
        cout << node << endl;
    }
}
int main()
{
    int v;
    cin >> v;
    int e;
    cin >> e;
    vector<list<int>> tree(v + 1, list<int>());
    while (e--)
    {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }
    kthParent_BinaryLifting(tree, v);
}