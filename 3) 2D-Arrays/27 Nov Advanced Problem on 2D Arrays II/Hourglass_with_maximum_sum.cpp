// You are given an m x n integer matrix grid. 
// Here,m>=3 and n>=3.

// We define an hourglass as a part of the matrix with the following shape:  {{A,A,A},
//          { ,A, },
//          {A,A,A}}

// Q1 - Given a 2D matrix with m rows and n columns containing integers.
// Return the maximum sum of the elements of an hourglass.
// Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

// Sample Input: [[1,2,3],
//                [4,5,6],
//                [7,8,9]]

// Sample Output: 35
// Explanation: This has only one hourglass shape i.e. 1+2+3+5+7+8+9=35

// Sample Input: [[6,2,1,3],
//                [4,2,1,5],
//                [9,2,8,7],
//                [4,1,2,9]]

// Sample Output:30
// Explanation: Amongst all possible hourglass in this matrix the maximum sum will be of the hourglass
// 6+2+1+2+9+2+8


#include<iostream>
#include<vector>
using namespace std;
int hourglass(vector<vector<int>> &a,int l1,int r1)
{
    return (a[l1][r1]+a[l1][r1+1]+a[l1][r1+2]+a[l1+1][r1+1]+a[l1+2][r1]+a[l1+2][r1+1]+a[l1+2][r1+2]);
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    int maxi=0;
    for(int i=0;i<m-2;i++)
    {
        for(int j=0;j<n-2;j++) 
        {
            int ans=hourglass(a,i,j);
            maxi=max(maxi,ans);
        }
    }
    cout<<maxi<<endl;
}