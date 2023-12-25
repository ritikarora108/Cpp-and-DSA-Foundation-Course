#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string largestPalindromicNumber(string &s)
{
    int n=s.length();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[s[i]-'0']++;
    }
    vector<char> v(n);
    int idx=0;
    bool flag=false;
    char x=' ';
    for(int i=9;i>=0;i--)
    {
        if(m[i]%2==1)
        {
            if(flag) return "-1";
            m[i]--;
            flag=true;
            x=i+'0';
        }
        while(m[i]!=0)
        {
            v[idx]=i+'0';
            v[n-idx-1]=i+'0';
            idx++;
            m[i]-=2;
        }
        
    }
    if(flag) v[n/2]=x;
    int j=0;
    for(auto i:v)
    {
        s[j++]=i;
    }
    return s;
}
int main()
{
    string s;
    cin>>s;
    cout<<largestPalindromicNumber(s)<<endl;
}