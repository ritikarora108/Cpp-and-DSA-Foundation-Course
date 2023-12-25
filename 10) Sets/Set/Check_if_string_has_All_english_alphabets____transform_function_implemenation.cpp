#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
bool containsAllLetters(string s)
{
    int n=s.length();
    if(n<26) return 0;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    set<char> alpha;
    for(auto i:s)
    {
        alpha.insert(i);
    }
    if(n<26) return 0;
    return 1;
}
int main()
{
    string s;
    cin>>s;
    cout<<containsAllLetters(s)<<endl;
    return 0;
}