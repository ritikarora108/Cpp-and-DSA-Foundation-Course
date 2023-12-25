//Space Complexity : O(log q)
//Time Complexity: O(log q)
#include<iostream>
using namespace std;
int power(int p,int q)
{
    if(q==0) return 1;
    int ans=power(p,q/2);
    if(q%2==0) return ans*ans;
    else return p*ans*ans;
}
int main()
{
    int p,q;
    cin>>p>>q;
    cout<<power(p,q)<<endl;
    return 0;
}