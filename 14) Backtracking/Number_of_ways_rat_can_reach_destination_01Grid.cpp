#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>> &grid)
{
    int n=grid.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<"********************"<<endl;
}
bool canWeGo(int row,int col,vector<vector<int>> &grid)
{
    int n=grid.size();
    return (row>=0 && row<n && col>=0 && col<n && grid[row][col]==1);
}
int numberOfPossiblePaths(int i,int j,vector<vector<int>> &grid)
{
    int n=grid.size();
    if(i==n-1 && j==n-1)
    {
        print(grid);
        return 1;
    }                             //                                                 ^
                          //                                                         |
    grid[i][j]=2;         // Visited marked so that rat doesn't move <- r -> and     r
    int ans=0;            //                                                         |
                                 //                                                  V
    if(canWeGo(i,j+1,grid)) ans+=numberOfPossiblePaths(i,j+1,grid);  // Rightwards
    if(canWeGo(i+1,j,grid)) ans+=numberOfPossiblePaths(i+1,j,grid);  // Downwards
    if(canWeGo(i,j-1,grid)) ans+=numberOfPossiblePaths(i,j-1,grid);  // Leftwards
    if(canWeGo(i-1,j,grid)) ans+=numberOfPossiblePaths(i-1,j,grid);  // Upwards

    grid[i][j]=1;
    return ans; 
}
int main()
{
    // Rat is initially at source (0,0,) and want to reach destination (n-1,n-1) in nXn grid
    // Rat can move upwards, leftwards, rightwards and downwards
    vector<vector<int>> grid={{1,1,1,1},{0,1,0,1},{0,1,1,1},{0,1,1,1}}; // 1 active state , where rat can move
                                                                        // 0-> blocked state
    int num=numberOfPossiblePaths(0,0,grid);
    cout<<"Possible Number of paths to reach destination : "<<num<<endl;
    return 0;
}