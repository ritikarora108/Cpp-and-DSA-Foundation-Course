#include<iostream>
#include<vector>
using namespace std;
int rectangleSum(vector<vector<int>> &a,int l1,int r1,int l2,int r2)
{
    int total_sum=a[l2][r2];

    int left_sum;
    if(r1==0) left_sum=0; 
    else left_sum=a[l2][r1-1];

    int top_sum;
    if(l1==0) top_sum=0;
    else top_sum=a[l1-1][r2];

    int top_left_sum;
    if(l1==0 || r1==0)  top_left_sum=0;
    else top_left_sum=a[l1-1][r1-1];

    return (total_sum - left_sum - top_sum + top_left_sum);
}
void prefixSumRow(vector<vector<int>> &a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=1;j<a[0].size();j++)
        {
            a[i][j]+=a[i][j-1];
        }
    }
}
void prefixSumColumn(vector<vector<int>> &a)
{
    for(int j=0;j<a[0].size();j++)
    {
        for(int i=1;i<a.size();i++)
        {
            a[i][j]+=a[i-1][j];
        }
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns of matrix: "<<endl;
    cin>>m>>n;
    cout<<"Enter the elements of matrix: "<<endl;
    vector<vector<int>> a(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }

    // Prefix sum Over columns and Rows Both
    prefixSumRow(a);
    cout<<"Prefix Sum Row Matrix: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    prefixSumColumn(a);
    cout<<"Prefix Sum Row and Column Matrix :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Enter the co-ordinates of both the points in the order (l1,r1,l2,r2):"<<endl;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    cout<<"Sum of rectangle is: ";
    int ans=rectangleSum(a,l1,r1,l2,r2);
    cout<<ans<<endl;
    return 0;
}