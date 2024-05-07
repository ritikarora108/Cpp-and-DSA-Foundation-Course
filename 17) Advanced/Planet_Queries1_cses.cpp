//******************************************************************
//						Author: Ritik Arora
#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

#define pp pair<int, int>
#define ppl pair<ll, ll>
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define nline '\n'
#define inf LLONG_MAX
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<long long>
#define vvl vector<vector<long long>>
ll mod1 = 1e9 + 7;
ll mod2 = 998244353;

bool revsort(ll a, ll b) { return a > b; }
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

int parent[200005][30];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int planet;
        cin >> planet;
        parent[i][0] = planet;
    }
    for (int i = 1; i <= 29; i++)
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
    for (int i = 1; i <= q; i++)
    {
        int node, pLevel;
        cin >> node >> pLevel;
        while (pLevel > 0)
        {
            int x = log2(pLevel);
            node = parent[node][x];
            pLevel -= (1 << x);
        }
        cout << node << nline;
    }
}
int main()
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
    while (t--)
    {
        solve();
    }
    return 0;
}