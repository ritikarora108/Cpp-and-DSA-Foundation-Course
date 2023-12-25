#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<ll> dp(x+1,0);
    dp[0]=1;
    int N=1e9+7;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-coins[i]<0) continue;
            dp[j]+=dp[j-coins[i]];
            dp[j]%=N;
        }
    }
    // for(int i=0;i<=x;i++)
    // {
    //     cout<<i<<"-"<<dp[i]<<endl;
    // }
    cout<<dp[x]<<endl;
}