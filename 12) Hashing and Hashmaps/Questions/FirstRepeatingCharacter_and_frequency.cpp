#include<iostream>
#include<unordered_map>
using namespace std;
pair<char,int> firstRepeatingCharacter(string s)
{
    unordered_map<char,int> m;
    int idx=-1;
    for(int i=0;i<s.length();i++)
    {
        if(m.find(s[i])!=m.end()) 
        {
            idx=i;
			break;
        }
        else m[s[i]]++;
    }
    if(idx==-1) return {' ',0};
    char x=s[idx];
    m[x]++;
    for(int i=idx+1;i<s.length();i++)
    {
        if(s[i]==x) m[x]++;
    }
    return {x,m[x]};
}
int main()
{
    string s;
    cin>>s;
    auto it=firstRepeatingCharacter(s);
    if(it.first!=' ' && it.second!=0) cout<<it.first<<" "<<it.second<<endl;
    else cout<<"No Repeating Characters"<<endl;
    return 0;
}