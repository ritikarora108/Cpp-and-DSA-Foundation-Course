#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int m;
    cin>>m;
    vector<int> a(m);
    set<int> s1;
    for(int i=0;i<m;i++) 
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    int n;
    cin>>n;
    vector<int> b(n);
    set<int> s2;
    for(int i=0;i<n;i++) 
    {
        cin>>b[i];
        s2.insert(b[i]);
    }
    int sum=0;
    for(auto i:s1)
    {
        if(s2.count(i)) sum+=i;
    }
    cout<<sum;

}