#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool canStringsBeEqual(vector<string> &words)
{
    unordered_map<char,int> m;
    int n=words.size();
    for(string s:words)
    {
        for(char x:s)
        {
            m[x]++;
        }
    }
    for(auto pair:m)
    {
        if(pair.second%n!=0) return false;
    }
    return true;
    
}
int main()
{
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++) cin>>words[i];
    cout<<(canStringsBeEqual(words) ? "Yes" : "No")<<endl;
    return 0;
}