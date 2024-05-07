//******************************************************************
//						Author: Ritik Arora
#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define int long long

int parent[200001][20];
int level[200001];
int kthParent(int node, int upLevel)
{
    if (upLevel == 0)
        return node;
    int x = log2(upLevel);
    return kthParent(parent[node][x], upLevel - (1 << x));
}
int find_lca(int a, int b, int limit)
{
    if (level[a] > level[b])
    {
        swap(a, b);
    }
    int d = level[b] - level[a];
    b = kthParent(b, d);

    if (a == b)
        return a;

    for (int i = limit - 1; i >= 0; i--)
    {
        if (parent[a][i] != -1 && (parent[a][i] != parent[b][i]))
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}
void dfs(int node, int par, int lvl, list<int> *tree)
{
    level[node] = lvl;
    parent[node][0] = par;
    for (auto ngh : tree[node])
    {
        if (ngh != par)
        {
            dfs(ngh, node, lvl + 1, tree);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    list<int> *tree = new list<int>[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int maxLevel = log2(n) + 1;
    dfs(1, -1, 0, tree);
    for (int i = 1; i < maxLevel; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            int itr = parent[node][i - 1];
            if (itr != -1)
            {
                parent[node][i] = parent[itr][i - 1];
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int lca = find_lca(a, b, maxLevel);
        cout << (-2 * level[lca] + level[a] + level[b]) << endl;
    }
    // delete[] tree;
}
signed main()
{
// StringHash hash(word);
// hash.substrHash(idx1,idx2)==hash.substrHash(idx3,idx4);
// Trie* T = new Trie();
// string ritik="ritik";
// T->insertNode(ritik);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
