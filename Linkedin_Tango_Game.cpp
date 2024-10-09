#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

map<pii, vector<pii>> equals;
map<pii, vector<pii>> unequals;

void getPairs(map<pii, vector<pii>> &mp)
{
    int a, b, c, d;
    while (true)
    {
        cin >> a >> b >> c >> d;
        if (a == -1 || b == -1 || c == -1 || d == -1)
            break;
        a--;
        b--;
        c--;
        d--;
        mp[{a, b}].push_back({c, d});
        mp[{c, d}].push_back({a, b});
    }
}

bool adjacent_valid(vector<vector<int>> &grid, int m, int n, int i, int j, int value)
{
    // Check the neighbors to ensure that the same entity doesn't appear more than twice consecutively
    int leftValues = ((j >= 1) ? (grid[i][j - 1] == value) : 0) + ((j >= 2) ? (grid[i][j - 2] == value) : 0);
    int upValues = ((i >= 1) ? (grid[i - 1][j] == value) : 0) + ((i >= 2) ? (grid[i - 2][j] == value) : 0);
    int rightValues = ((j < n - 1) ? (grid[i][j + 1] == value) : 0) + ((j < n - 2) ? (grid[i][j + 2] == value) : 0);
    int downValues = ((i < m - 1) ? (grid[i + 1][j] == value) : 0) + ((i < m - 2) ? (grid[i + 2][j] == value) : 0);

    return (leftValues < 2) && (upValues < 2) && (rightValues < 2) && (downValues < 2);
}

bool check_validity(vector<vector<int>> &grid, int m, int n)
{
    // Check if the placement is valid row-wise and column-wise
    for (int i = 0; i < m; i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                cnt1++;
            else if (grid[i][j] == 2)
                cnt2++;

            // Check adjacent validity as well
            if (grid[i][j] != 0 && !adjacent_valid(grid, m, n, i, j, grid[i][j]))
            {
                return false;
            }
        }
        if (cnt1 > n / 2 || cnt2 > n / 2)
            return false;
    }

    // Check column-wise
    for (int j = 0; j < n; j++)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[i][j] == 1)
                cnt1++;
            else if (grid[i][j] == 2)
                cnt2++;
        }
        if (cnt1 > m / 2 || cnt2 > m / 2)
            return false;
    }
    return true;
}

bool placeValues(vector<vector<int>> &grid, int m, int n, int i, int j, int value, vector<pair<pii, int>> &orgs)
{
    // Handle equals constraints
    for (auto &pr : equals[{i, j}])
    {
        int new_i = pr.first, new_j = pr.second;
        orgs.push_back({{new_i, new_j}, grid[new_i][new_j]});
        if (grid[new_i][new_j] == 0)
        {
            grid[new_i][new_j] = value;
            if (!check_validity(grid, m, n))
                return false;
        }
        else if (grid[new_i][new_j] != value)
        {
            return false;
        }
    }

    // Handle unequals constraints
    for (auto &pr : unequals[{i, j}])
    {
        int new_i = pr.first, new_j = pr.second;
        orgs.push_back({{new_i, new_j}, grid[new_i][new_j]});
        if (grid[new_i][new_j] == 0)
        {
            grid[new_i][new_j] = 3 - value; // Flip between 1 (sun) and 2 (moon)
            if (!check_validity(grid, m, n))
                return false;
        }
        else if (grid[new_i][new_j] != 3 - value)
        {
            return false;
        }
    }
    return true;
}

void resetMarkedValues(vector<pair<pii, int>> &orgs, vector<vector<int>> &grid)
{
    while (!orgs.empty())
    {
        int i = orgs.back().first.first, j = orgs.back().first.second;
        grid[i][j] = orgs.back().second;
        orgs.pop_back();
    }
}

bool populateGrid(vector<vector<int>> &grid, int m, int n, int i, int j)
{
    if (i == m)
    {
        cout << "Tango game output:\n";
        for (const auto &row : grid)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
        return true;
    }

    int next_i = i + (j == n - 1);
    int next_j = (j + 1) % n;

    vector<pair<pii, int>> orgs;
    if (grid[i][j] != 0)
    {
        if (placeValues(grid, m, n, i, j, grid[i][j], orgs))
        {
            if (populateGrid(grid, m, n, next_i, next_j))
                return true;
        }
        resetMarkedValues(orgs, grid);
        return false;
    }

    // Try placing '1' (sun) and '2' (moon)
    for (int value = 1; value <= 2; value++)
    {
        grid[i][j] = value;
        if (check_validity(grid, m, n))
        {
            if (placeValues(grid, m, n, i, j, value, orgs))
            {
                if (populateGrid(grid, m, n, next_i, next_j))
                    return true;
            }
        }
        resetMarkedValues(orgs, grid);
    }

    grid[i][j] = 0; // Backtrack
    return false;
}

void display(map<pii, vector<pii>> &mp)
{
    for (const auto &p : mp)
    {
        cout << "(" << p.first.first << "," << p.first.second << ") -> ";
        for (const auto &q : p.second)
            cout << "(" << q.first << "," << q.second << ") ";
        cout << endl;
    }
}
void fillGrid(vector<vector<int>> &grid, int m, int n, int val)
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 || b == -1)
            break;
        a--;
        b--;
        grid[a][b] = val;
    }
}

int main()
{
    equals.clear();
    unequals.clear();

    int m, n;
    cout << "Enter row col: ";
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    cout << "Enter sun pos:" << endl;
    fillGrid(grid, m, n, 1);
    cout << "Enter moon pos:" << endl;
    fillGrid(grid, m, n, 2);
    cout << "Enter equals pos:" << endl;
    getPairs(equals); // Get 'equals' constraints
    cout << "Enter unequals pos:" << endl;
    getPairs(unequals);   // Get 'unequals' constraints

    // cout << "Equals:\n";
    // display(equals);
    // cout << "Unequals:\n";
    // display(unequals);

    if (!populateGrid(grid, m, n, 0, 0))
        cout << "Some miscalculation happened!!" << endl;

    return 0;
}
