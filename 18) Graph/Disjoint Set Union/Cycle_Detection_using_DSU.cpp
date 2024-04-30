//  Time Complexity : O(E x log*V)
#include <bits/stdc++.h>
using namespace std;
int find(int x, vector<int> &parent)
{
    return parent[x] = (parent[x] == x) ? (x) : (find(parent[x], parent));
}
bool Union(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = find(a, parent);
    b = find(b, parent);
    if (a == b)
    {
        return true;
    }
    if (rank[a] >= rank[b])
    {
        rank[a]++;
        parent[b] = a;
    }
    else
    {
        rank[b]++;
        parent[a] = b;
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(n + 1, 0);
    bool flag = false;
    while (m--)
    {
        int s, d;
        cin >> s >> d;
        if (Union(s, d, parent, rank))
        {
            cout << "CYCLE DETECTED" << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "No cycle present" << endl;
}