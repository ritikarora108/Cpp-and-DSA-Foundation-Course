#include<iostream>
using namespace std;
int main()
{
    int a[2][3]={1,2,3,4,5,6};
    cout<<"Printing 2D-array a: "<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;

    int b[3][2]={{1,2},{7,8},{9,4}};
    cout<<"Printind 2D-Array b:"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++) cout<<b[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;

    int m,n;
    cout<<"Enter the Number of Rows of 2D-Array c: ";
    cin>>m;
    cout<<"Enter the Number of Columns of 2-D Array c: ";
    cin>>n;
    int c[m][n];
    cout<<"Taking input one-by-one in this 2D-Array : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>c[i][j];
    }
    cout<<endl;
    cout<<"Printing every element of 2D-Array c in the form of matrix: "<<endl;
    for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++) cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}