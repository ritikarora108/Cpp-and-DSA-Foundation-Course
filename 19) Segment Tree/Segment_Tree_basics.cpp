#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void segmentTree(vector<int> &v, vector<int> &segTree, int i, int l, int r)
{
    if (l == r)
    {
        segTree[i] = v[l];
        return;
    }
    int mid = l + (r - l) / 2;
    segmentTree(v, segTree, 2 * i + 1, l, mid);
    segmentTree(v, segTree, 2 * i + 2, mid + 1, r);
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}
int getMax(vector<int> &segTree, int s, int e, int i, int l, int r)
{
    if (r < s || l > e)
        return -1;
    if (l >= s && r <= e)
        return segTree[i];
    int mid = l + (r - l) / 2;
    return max(getMax(segTree, s, e, 2 * i + 1, l, mid), getMax(segTree, s, e, 2 * i + 2, mid + 1, r));
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> segTree(4 * n, -1);
    segmentTree(v, segTree, 0, 0, n - 1);
}