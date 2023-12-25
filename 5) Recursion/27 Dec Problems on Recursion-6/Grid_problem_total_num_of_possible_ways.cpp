// #include<iostream>
// using namespace std;
// int factorial(int n)
// {
//     if(n==1) return 1;
//     return n*factorial(n-1);
// }
// int main()
// {
//     int m,n;
//     cin>>m>>n;
//     int ans = factorial(m+n-2) / (factorial(m-1) * factorial(n-1));
//     cout<<ans<<endl;
//     return 0;
// }

#include<iostream>
using namespace std;
int count(int i,int j,int m,int n)
{
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    return count(i,j+1,m,n) + count(i+1,j,m,n);
} 
int main()
{
    int m,n;
    cin>>m>>n;
    // vector<vector<int>> grid(m,vector<int> (n));
    int i=0,j=0;
    int numOfPossibleWays = count(i,j,m,n);
    // Counts the total possible ways to reach grid->(m-1,n-1) from grid->(0,0)
    cout<<numOfPossibleWays<<endl;
    return 0;
}