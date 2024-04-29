#include <bits/stdc++.h>
using namespace std;
#define ll long long
void eulertour2(vector<list<int>> &adj, int src, int parent, vector<ll> &arr)
{
    arr.push_back(src);

    for (auto ngh : adj[src])
    {
        if (ngh != parent)
        {
            eulertour2(adj, ngh, src, arr);
        }
    }
    arr.push_back(-src);
}
#define ll long long
class segmentTree
{

public:
    vector<ll> segTree;
    segmentTree(int n)
    {
        segTree.resize(4 * n + 10, 0);
    }
    ll merge(ll p, ll q)
    {
        return p + q;
    }
    void build(ll idx, ll l, ll r, vector<ll> &a, vector<ll> &values)
    {
        if (l == r)
        {
            segTree[idx] = (2 * (a[l] > 0) - 1) * values[abs(a[l])];
            return;
        }
        ll m = (l + r) / 2;
        build(idx * 2 + 1, l, m, a, values);
        build(idx * 2 + 2, m + 1, r, a, values);
        segTree[idx] = merge(segTree[idx * 2 + 1], segTree[idx * 2 + 2]);
    }
    void update(ll idx, ll l, ll r, ll i, ll j, ll x)
    {
        if (l > j or i > r or l > r)
            return;
        if (i == l and r == j)
        {
            segTree[idx] = x;
            return;
        }
        ll m = (l + r) / 2;
        update(idx * 2 + 1, l, m, i, j, x);
        update(idx * 2 + 2, m + 1, r, i, j, x);
        segTree[idx] = merge(segTree[idx * 2 + 1], segTree[idx * 2 + 2]);
    }

    ll query(ll idx, ll l, ll r, ll i, ll j)
    {
        if (l > j or i > r or l > r)
            return 0;
        if (i <= l and r <= j)
        {
            return segTree[idx];
        }
        ll m = (l + r) / 2;
        ll ans = merge(query(idx * 2 + 1, l, m, i, j), query(idx * 2 + 2, m + 1, r, i, j));

        return ans;
    }
};
void dfs(int u, int p, ll **memo, vector<ll> &lev, int log, vector<list<int>> &g)
{
    // Using recursion formula to calculate
    // the values of memo[][]
    memo[u][0] = p;
    for (int i = 1; i <= log; i++)
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v != p)
        {
            lev[v] = lev[u] + 1;
            dfs(v, u, memo, lev, log, g);
        }
    }
}

// Function to return the LCA of nodes u and v
int lca(int u, int v, ll log, vector<ll> &lev, ll **memo)
{
    // The node which is present farthest
    // from the root node is taken as u
    // If v is farther from root node
    // then swap the two
    if (lev[u] < lev[v])
        swap(u, v);

    // Finding the ancestor of u
    // which is at same level as v
    for (ll i = log; i >= 0; i--)
        if ((lev[u] - 1ll << i) >= lev[v])
            u = memo[u][i];

    // If v is the ancestor of u
    // then v is the LCA of u and v
    if (u == v)
        return u;

    // Finding the node closest to the root which is
    // not the common ancestor of u and v i.e. a node
    // x such that x is not the common ancestor of u
    // and v but memo[x][0] is
    for (int i = log; i >= 0; i--)
    {
        if (memo[u][i] != memo[v][i])
        {
            u = memo[u][i];
            v = memo[v][i];
        }
    }

    // Returning the first ancestor
    // of above found node
    return memo[u][0];
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> values(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }
    int log = (int)ceil(log2(n));
    ll **memo = new ll *[n + 1];
    for (int i = 0; i < n + 1; i++)
        memo[i] = new ll[log + 1];

    // Stores the level of each node
    vector<ll> lev(n + 1);

    // Initialising memo values with -1
    for (int i = 0; i <= n; i++)
        memset(memo[i], -1, sizeof memo[i]);
    vector<list<int>> adj(n + 1, list<int>());
    for (int i = 0; i <= n - 2; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> par(n + 1);
    vector<ll> arr;
    eulertour2(adj, 1, -1, arr);
    int sz = arr.size();
    vector<int> leftPtr(n + 1, -1);
    vector<int> rightPtr(n + 1, -1);
    segmentTree st(sz);
    st.build(0, 0, sz - 1, arr, values);
    dfs(1, 1, memo, lev, log, adj);
    for (int i = 0; i < sz; i++)
    {
        if (leftPtr[abs(arr[i])] == -1)
            leftPtr[abs(arr[i])] = i;
        rightPtr[abs(arr[i])] = i;
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll node, x;
            cin >> node >> x;
            values[node] = x;
            st.update(0, 0, sz - 1, leftPtr[node], leftPtr[node], x);
            st.update(0, 0, sz - 1, rightPtr[node], rightPtr[node], -x);
        }
        else
        {
            int a = 1, b;
            cin >> b;
            ll ans = st.query(0, 0, sz - 1, leftPtr[0], leftPtr[a]);
            ans += st.query(0, 0, sz - 1, leftPtr[0], leftPtr[b]);
            int up = lca(a, b, log, lev, memo);
            ans -= 2 * st.query(0, 0, sz - 1, leftPtr[0], leftPtr[up]);
            ans += values[up];
            cout << ans << endl;
        }
    }
}