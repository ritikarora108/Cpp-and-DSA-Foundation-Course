#include<iostream>
#include<vector>
using namespace std;
bool canPlaceKnight(vector<vector<char>> grid,int row,int col)
{
    int m=grid.size();
    int n=grid[0].size();
    if(row-1>=0 && col-2>=0 && grid[row-1][col-2]=='K') return false;
    if(row-2>=0 && col-1>=0 && grid[row-2][col-1]=='K') return false;
    if(row-1>=0 && col+2<n && grid[row-1][col+2]=='K') return false;
    if(row-2>=0 && col+1<n && grid[row-2][col+1]=='K') return false;
    return true;
}
void knights(vector<vector<char>> &grid,int row,int col,int cnt,int k,int &ans)
{
    if(cnt==k)
    {
        ans++;
        for(auto i:grid)
        {
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
        cout<<"************"<<endl;
        return;
    }
    int m=grid.size();
    int n=grid[0].size();
    if(col==n) {
        knights(grid,row+1,0,cnt,k,ans);
        return;
    }
    if(row==m) return;
    if(canPlaceKnight(grid,row,col))
    {
        grid[row][col]='K';
        knights(grid,row,col+1,cnt+1,k,ans);
        grid[row][col]='.';
    }
    knights(grid,row,col+1,cnt,k,ans);
}
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<char>> grid(m,vector<char> (n,'.'));
    int cnt=0;
    int ans=0;
    knights(grid,0,0,cnt,k,ans);
    cout<<ans;
}