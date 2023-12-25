#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> createSpiralOrderMatrix(int n)
{
    vector<vector<int>> grid(n,vector<int> (n));
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=n-1;
    int direction=0;
    int x=1;
    while(top<=bottom && left<=right)
    {
        if(direction==0)
        {
            for(int j=left;j<=right;j++) grid[top][j]=x++;
            top++;
        }
        else if(direction==1)
        {
            for(int i=top;i<=bottom;i++) grid[i][right]=x++;
            right--;
        }
        else if(direction==2)
        {
            for(int j=right;j>=left;j--) grid[bottom][j]=x++;
            bottom--;
        }
        else
        {
            for(int i=bottom;i>=top;i--) grid[i][left]=x++;
            left++;
        }
        direction++;
        direction=(direction%4);
    }
    return grid;
}
int main()
{
    int n;
    cout<<"Enter the size of sqaure matrix to be formed: ";
    cin>>n;
    vector<vector<int>> ans;
    ans=createSpiralOrderMatrix(n);
    cout<<"Desired Square Matrix formed: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}