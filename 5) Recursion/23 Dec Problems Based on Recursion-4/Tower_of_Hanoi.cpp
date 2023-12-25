#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    vector<ll> dp(n,0);
    //dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        dp[i]=INT_MAX;
        for(int jump=1;jump<=a[i];jump++)
        {
            if(i+jump>=n) break;
            dp[i]=min(dp[i],1+dp[i+jump]);
        }
    }
    for(auto i:dp)
    {
        cout<<i<<" ";
    }
}