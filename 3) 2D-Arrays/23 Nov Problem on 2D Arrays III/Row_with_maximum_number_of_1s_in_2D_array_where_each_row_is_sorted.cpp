// Given a boolean 2D array, where each row is sorted. 
// Find the row with the maximum number of 1s . 

//Ans: The row having the leftmost 1 is the row having maximum number of 1.
#include<iostream>
#include<vector>
using namespace std;
int maximumOnesRow(vector<vector<int>> &v)
{
    int m=v.size();
    int n=v[0].size();
    int j=n-1;
    int maximumOnesRowIndex=-1;
    for(int i=0;i<m;i++)
    {
        for(j;j>=0;j--)
        {
            if(v[i][j]==0) break;
            else maximumOnesRowIndex=i;
        }
        if(j<0) break;
    }
    return maximumOnesRowIndex;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> ans(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>ans[i][j];
    }
    int row_index=maximumOnesRow(ans);
    cout<<row_index<<endl;
    return 0;
}