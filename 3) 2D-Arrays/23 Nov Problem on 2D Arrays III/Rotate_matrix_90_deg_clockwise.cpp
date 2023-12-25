#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of square matrix: ";
    cin>>n;
    int a[n][n];
    cout<<"Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++) swap(a[i][j],a[j][i]);
    }
    cout<<"Transpose Matrix:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++) swap(a[i][j],a[i][n-j-1]);
    }
    cout<<"Matrix obtained after rotating 90 deg clockwise : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}