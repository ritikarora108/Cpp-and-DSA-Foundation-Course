//Given a m*n integer matrix. If an element of the matrix is 0,
//then set the complete row and column of that element to 0. 
//Make the changes inplace and print the matrix.

#include<iostream>
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
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                for(int row=0;row<m;row++) 
                {
                    if(arr[row][j]!=0) arr[row][j]=INT_MIN;
                }
                for(int col=0;col<n;col++) 
                {
                    if(arr[i][col]!=0) arr[i][col]=INT_MIN;
                }
            } 
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) 
        {
            if(arr[i][j]==INT_MIN) arr[i][j]=0;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}