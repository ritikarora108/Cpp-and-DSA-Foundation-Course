#include<iostream>
#include<vector>
using namespace std;
void helper(int n,int open,int close,string &s,vector<string> &ans)
{
    if(open==n && close==n) {
        ans.push_back(s);
        return;
    }
    if(open<n)
    {
        s+="(";
        helper(n,open+1,close,s,ans);
        s.pop_back();
    }
    if(close<open)
    {
        s+=")";
        helper(n,open,close+1,s,ans);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s="";
    helper(n,0,0,s,ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string> v=generateParenthesis(n);
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
    return 0;
}