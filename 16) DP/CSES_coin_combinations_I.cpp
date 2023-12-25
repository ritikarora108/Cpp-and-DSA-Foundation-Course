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
    int N=1e9+7;
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        ll ans=0;
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]<0) break;
            ans+=dp[i-coins[j]];
            ans%=N;
        }
        dp[i]=ans;
    }
    // for(int i=0;i<=x;i++)
    // {
    //     cout<<i<<"-"<<dp[i]<<endl;
    // }
    cout<<dp[x]<<endl;
}