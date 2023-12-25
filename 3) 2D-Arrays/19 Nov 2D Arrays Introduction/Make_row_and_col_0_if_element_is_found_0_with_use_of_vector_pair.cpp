//Given a m*n integer matrix. If an element of the matrix is 0,
//then set the complete row and column of that element to 0. 
//Make the changes inplace and print the matrix.

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0) ans.push_back({i,j});
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        int x=ans[i].first;
        int y=ans[i].second;
        int row=0;
        int col=0;
        while(row<m) arr[row++][y]=0;
        while(col<n) arr[x][col++]=0;
    }
    for(int i=0;i<m;i++)    
    {
        for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}