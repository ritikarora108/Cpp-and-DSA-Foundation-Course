#include<iostream>
#include<vector>
using namespace std;
int rectangleSum(vector<vector<int>> &a,int l1,int r1,int l2,int r2)
{
    int sum=0;
    for(int i=l1;i<=l2;i++)
    {
        if(r1!=0)
        {
            sum+=(a[i][r2]-a[i][r1-1]);
        }
        else sum+=a[i][r2];
    }
    return sum;
}
void prefixSumRow(vector<vector<int>> &a)
{
    if(a[0].size()!=1)
    {
        for(int i=0;i<a.size();i++)
        {
            for(int j=1;j<a[0].size();j++)
            {
                a[i][j]+=a[i][j-1];
            }
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
    //pre_calculating_the_prefix_sum_row_wise
    prefixSumRow(a);
    cout<<"Enter the co-ordinates of both the points in the order (l1,r1,l2,r2):"<<endl;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    cout<<"Sum of rectangle is: ";
    int ans=rectangleSum(a,l1,r1,l2,r2);
    cout<<ans<<endl;
    return 0;
}