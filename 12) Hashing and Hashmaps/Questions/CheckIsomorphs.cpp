#include<iostream>
#include<unordered_map>
using namespace std;
bool checkIsomorphs(string a,string b)
{
    int l1=a.length();
    int l2=b.length();
    if(l1!=l2) return false;
    unordered_map<char,char> m;
    for(int i=0;i<l1;i++)
    {
        auto it1=m.find(a[i]);
        auto it2=m.find(b[i]);
        if(it1==m.end() && it2==m.end()) 
        {
            m[a[i]]=b[i];
            m[b[i]]=a[i];
        }
        else{
            if((it1!=m.end() && m[a[i]]!=b[i])) return false;
            if((it2!=m.end() && m[b[i]]!=a[i])) return false;
        }
    }
    return true;
    
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<(checkIsomorphs(s1,s2) ? ("Yes,they are isomorphs") : ("No, they are not isomorphs"))<<endl;
    return 0;
}