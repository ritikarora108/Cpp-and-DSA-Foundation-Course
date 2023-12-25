#include<iostream>
#include<vector>
using namespace std;
void spiralOrderPrinting(vector<vector<int>> &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int first_row=0;
    int last_row=m-1;
    int first_column=0;
    int last_column=n-1;
    while(first_row<=last_row && first_column<=last_column)
    {
        for(int j=first_column;j<=last_column;j++) cout<<matrix[first_row][j]<<" ";
        first_row++;
        if(first_row>last_row) break;
        for(int i=first_row;i<=last_row;i++) cout<<matrix[i][last_column]<<" ";
        last_column--;
        if(last_column<first_column) break;
        for(int j=last_column;j>=first_column;j--) cout<<matrix[last_row][j]<<" ";
        last_row--;
        if(last_row<first_row) break;
        for(int i=last_row;i>=first_row;i--) cout<<matrix[i][first_column]<<" ";
        first_column++;
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns respectively :"<<endl;
    cin>>m>>n;
    //Formation of a 2D-vector
    vector<vector<int>> matrix(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>matrix[i][j];
    }
    cout<<"Printing in Spiral Order: "<<endl;
    spiralOrderPrinting(matrix);
    return 0;
}