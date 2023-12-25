#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotation_90deg_clockwise(vector<vector<int>> &arr)
{
    //transpose of matrix
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<i;j++) swap(arr[i][j],arr[j][i]);
    }

    //reverse each row
    for(int i=0;i<arr.size();i++)
    {
        reverse(arr[i].begin(),arr[i].end());
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    rotation_90deg_clockwise(arr);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}