#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>> &chess)
{
    int n=chess.size();
    for(auto likeString : chess)
    {
        for(char ch: likeString) cout<<ch<<" ";
        cout<<endl;
    }
    cout<<"*****************"<<endl;
}
bool canPlaceQueen(int row,int col,vector<vector<char>> &chess)
{
    int n=chess.size();
    for(int i=row-1;i>=0;i--)  
    { 
        if(chess[i][col]=='Q') return false;          // Vertical Attack
    } 
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(chess[i][j]=='Q') return false;           // Left Up Diagonal Attack
    }
    for(int i=row-1,j=col+1 ;i>=0 && j<n;i--,j++)
    {
        if(chess[i][j]=='Q') return false;           // Right Up Diagonal Attack
    }

    return true;
}
void NQueens(int currRow,int n,vector<vector<char>> &chess,int &numberOfPossibleWays)
{
    if(currRow==n)
    {
        print(chess);
        numberOfPossibleWays++;
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(canPlaceQueen(currRow,col,chess))
        {
            chess[currRow][col]='Q';
            NQueens(currRow+1,n,chess,numberOfPossibleWays);
            chess[currRow][col]='.';
        }
    }
}
int main()
{   
    // NQueens
    int n;
    cin>>n; // nXn chess board
    int numberOfPossibleWays=0;
    vector<vector<char>> chess(n,vector<char>(n,'.'));
    NQueens(0,n,chess,numberOfPossibleWays);
    cout<<"Possible ways to place queens in N x N chessboard: "<<numberOfPossibleWays<<endl;
}