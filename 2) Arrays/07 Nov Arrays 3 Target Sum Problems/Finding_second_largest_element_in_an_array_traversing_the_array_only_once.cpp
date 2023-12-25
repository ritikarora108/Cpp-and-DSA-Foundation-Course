#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int maxi=INT_MIN;
    int second_maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxi)
        {
            second_maxi=maxi;
            maxi=a[i];
        }
        else if(second_maxi<a[i] && a[i]!=maxi)
        {
            second_maxi=a[i];
        }
    }
    cout<<second_maxi<<endl;
}