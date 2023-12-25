#include<iostream>
#include<vector>
using namespace std;
bool knightTour(vector<vector<int>> &grid,int n,int i,int j,int k)
{
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=-1) return false;
    grid[i][j]=k;
    if(k==n*n-1) 
    {
        for(auto i:grid)
        {
            for(auto j:i) cout<<j<<"\t";
            cout<<endl;
        }
        return true;
    }
    bool res= knightTour(grid,n,i+1,j+2,k+1) || knightTour(grid,n,i+2,j+1,k+1) || knightTour(grid,n,i+1,j-2,k+1)
        || knightTour(grid,n,i+2,j-1,k+1) || knightTour(grid,n,i-1,j+2,k+1) || knightTour(grid,n,i-1,j-2,k+1)
        || knightTour(grid,n,i-2,j+1,k+1) || knightTour(grid,n,i-2,j-1,k+1);

        if(res) return true;
        grid[i][j]=-1;
        return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int> (n,-1));
    int k=0;
    knightTour(grid,n,0,0,k);
    return 0;
}