#include<iostream>
#include<unordered_map>
using namespace std;
bool checkAnagram(string a,string b)
{
    int l1=a.length();
    int l2=b.length();
    if(l1!=l2) return false;
    unordered_map<char,int> m;
    for(int i=0;i<l1;i++)
    {
        m[a[i]]++;
        m[b[i]]--;
    }
    for(auto pair:m)
    {
        if(pair.second!=0) return false;
    }
    return true;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<(checkAnagram(s1,s2) ? ("Yes, they are anagrams") : ("No, they are not anagrams"))<<endl;
    return 0;
}