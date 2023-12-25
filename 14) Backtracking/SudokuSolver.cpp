#include<iostream>
#include<vector>
using namespace std;
bool canPlaceVal(int row,int col,int val,vector<vector<int>> &grid)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==val) return false;
    }
    for(int j=0;j<9;j++)
    {
        if(grid[row][j]==val) return false;
    } 
    for(int i=(row/3)*3;i<(row/3)*3+3;i++)
    {
        for(int j=(col/3)*3;j<(col/3)*3+3;j++)
        {
            if(grid[i][j]==val) return false;
        }
    }
    return true;
}
bool sudokuSolver(vector<vector<int>> &grid,int row,int col)
{
    if(col==9) return sudokuSolver(grid,row+1,0);
    if(row==9) return true;
    if(grid[row][col]==0)
    {
        for(int val=1;val<=9;val++)
        {
            if(canPlaceVal(row,col,val,grid))
            {
                grid[row][col]=val;
                bool res=sudokuSolver(grid,row,col+1);
                if(res) return true;
                grid[row][col]=0;
            }
        }
        return false;
    }
    
    return sudokuSolver(grid,row,col+1);
    
}
int main()
{
    vector<vector<int>> grid= {{3,0,6,5,0,8,4,0,0},
    {5,2,0,0,0,0,0,0,0},
    {0,8,7,0,0,0,0,3,1},
    {0,0,3,0,1,0,0,8,0},
    {9,0,0,8,6,3,0,0,5},
    {0,5,0,0,9,0,6,0,0},
    {1,3,0,0,0,0,2,5,0},
    {0,0,0,0,0,0,0,7,4},
    {0,0,5,2,0,6,3,0,0}
    };
    //vector<vector<int>> ans;
    if(sudokuSolver(grid,0,0))
    {
        for(auto i:grid)
        {
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
    }
    else cout<<"Not possible";
}