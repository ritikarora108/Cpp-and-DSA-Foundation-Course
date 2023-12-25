#include<iostream>
#include<vector>
using namespace std;
int rectangleSum(vector<vector<int>> &a,int l1,int r1,int l2,int r2)
{
    int sum=0;
    for(int i=l1;i<=l2;i++)
    {
        for(int j=r1;j<=r2;j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
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
    cout<<"Enter the co-ordinates of both the points in the order (l1,r1,l2,r2):"<<endl;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    cout<<"Sum of rectangle is: ";
    int ans=rectangleSum(a,l1,r1,l2,r2);
    cout<<ans<<endl;
    return 0;
}