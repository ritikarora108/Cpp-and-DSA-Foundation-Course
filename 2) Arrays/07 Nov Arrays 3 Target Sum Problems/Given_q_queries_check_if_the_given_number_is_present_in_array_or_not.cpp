//Value of element in the array is less than or equal to 10^5.

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++) cin>>v[i];
    const int N = 1e5+10;
    vector<int> freq(N,0);
    for(int i=0;i<n;i++)
    {
        freq[v[i]]++;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int queryElement;
        cin>>queryElement;
        cout<<freq[queryElement]<<endl;
    }
}