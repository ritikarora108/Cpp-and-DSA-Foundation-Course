#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the row and column of a: "<<endl;
    int m,n;
    cin>>m>>n;
    cout<<endl;
    int a[m][n];
    cout<<"Taking Input of a: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    cout<<endl;
    cout<<"Enter the row and column of b: "<<endl;
    int p,q;
    cin>>p>>q;
    cout<<endl;
    int b[p][q];
    cout<<"Taking Input of b:"<<endl;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++) cin>>b[i][j];
    }
    cout<<endl;

    if(n!=p) 
    {
        cout<<"Matrix Mutiplication not possible for these inputs."<<endl;
        return 0;
    }

    int c[m][q];
    cout<<"Printing resultant matrix c: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<q;j++) 
        {
            int ans=0;
            for(int k=0;k<n;k++)
            {
                ans+=a[i][k]*b[k][j];
            }
            c[i][j]=ans;
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}