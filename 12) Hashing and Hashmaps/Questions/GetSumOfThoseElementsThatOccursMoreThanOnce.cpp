#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int getDuplicateSum(vector<int> &v)
{
    unordered_map<int,int> m;
    for(int i:v) m[i]++;
    int sum=0;
    for(auto pair:m)
    {
        if(pair.second>1) sum+=pair.first;
    }
    return sum;
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
    int ans=getDuplicateSum(v);
    cout<<ans;
}