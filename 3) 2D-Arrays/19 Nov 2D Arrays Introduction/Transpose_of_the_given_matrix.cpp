#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the row and column of matrix:"<<endl;
    cin>>m>>n;
    int arr[m][n];
    cout<<"Taking Input Matrix from user:"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    cout<<endl;
    
    int ans[n][m];
    cout<<"Transpose of the given matrix is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            ans[i][j]=arr[j][i];
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}