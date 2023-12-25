/*
    Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dpTopDown;
int minCost(vector<int> &v,int i,int j)
{
    if(dpTopDown[i][j]!=-1) return dpTopDown[i][j];
    if(i==j-1) return dpTopDown[i][j]=0;
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        ans=min(ans,minCost(v,i,k)+minCost(v,k,j)+v[i]*v[k]*v[j]);
    }
    return dpTopDown[i][j]=ans;
}
int matrixChainMultiplication(vector<int> &v)
{
    dpTopDown.resize(v.size(),vector<int>(v.size(),-1));
    return minCost(v,0,v.size()-1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    } 
    //cout<<matrixChainMultiplication(v)<<endl;   // top down approach

    vector<vector<int>> dpBottomUp(n,vector<int>(n,0));
    for(int len=2;len<n;len++)
    {
        for(int i=0;i+len<n;i++)
        {
            int j=i+len;
            dpBottomUp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dpBottomUp[i][j]=min(dpBottomUp[i][j],dpBottomUp[i][k]+dpBottomUp[k][j]+v[i]*v[k]*v[j]);
            }
        }
    }
    cout<<dpBottomUp[0][n-1]<<endl;
}