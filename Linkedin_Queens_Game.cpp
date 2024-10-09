#include <bits/stdc++.h>
using namespace std;

bool mark(vector<vector<char>> &ans, int i, int j, map<char, vector<vector<int>>> &mp, vector<vector<char>> &grid, int m, int n)
{
    for (int row = 0; row < m; row++)
    {
        if (ans[row][j] == 'Q')
            return false;
        ans[row][j] = 'x';
    }
    for (int col = 0; col < n; col++)
    {
        if (ans[i][col] == 'Q')
            return false;
        ans[i][col] = 'x';
    }
    for (int row = i - 1; row <= i + 1; row++)
    {
        for (int col = j - 1; col <= j + 1; col++)
        {
            if (row < 0 || row >= m || col < 0 || col >= n)
                continue;
            if (ans[row][col] == 'Q')
                return false;
            ans[row][col] = 'x';
        }
    }
    for (auto v : mp[grid[i][j]])
    {
        if (ans[v[0]][v[1]] == 'Q')
            return false;
        ans[v[0]][v[1]] = 'x';
    }
    return true;
}
bool func(vector<vector<char>> &ans, int i, map<char, vector<vector<int>>> &mp, int m, int n, vector<vector<char>> &grid)
{
    if (i == m)
    {
        cout << endl;
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return true;
    }
    vector<vector<char>> org = ans;
    for (int j = 0; j < n; j++)
    {
        if (ans[i][j] == '.')
        {
            if (!mark(ans, i, j, mp, grid, m, n))
            {
                ans = org;
                continue;
            }
            ans[i][j] = 'Q';
            if (func(ans, i + 1, mp, m, n, grid))
                return true;
            ans = org;
        }
    }
    return false;
}
void solve(vector<vector<char>> &grid, int m, int n)
{
    map<char, vector<vector<int>>> mp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[grid[i][j]].push_back({i, j});
        }
    }
    vector<vector<char>> ans(m, vector<char>(n, '.'));
    func(ans, 0, mp, m, n, grid);
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    solve(grid, m, n);
}