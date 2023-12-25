#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void permutations(int i,string s,vector<string> &ans)
{
    int n=s.length();
    if(i==n) 
    {
        ans.push_back(s);
        return;
    }
    for(int j=i;j<n;j++)
    {
        swap(s[i],s[j]);
        permutations(i+1,s,ans);
        swap(s[j],s[i]);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<string> res;
    permutations(0,s,res);
    sort(res.begin(),res.end());
    cout<<"Permutations in lexicographically sorted manner: "<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}