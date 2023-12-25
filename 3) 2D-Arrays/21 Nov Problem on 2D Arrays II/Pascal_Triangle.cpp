// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>> pascalTriangle(int n)
// {
//     vector<vector<int>> pascal(n);
//     for(int i=0;i<pascal.size();i++)
//     {
//         pascal[i].resize(i+1);
//     }
//     for(int i=0;i<pascal.size();i++)
//     {
//         for(int j=0;j<pascal[i].size();j++)
//         {
//             if(j==0 || i==j) pascal[i][j]=1;
//             else pascal[i][j]=(i*pascal[i-1][j])/(i-j);
//         }
//     }
//     return pascal;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<vector<int>> ans;
//     ans=pascalTriangle(n);
//     for(int i=0;i<ans.size();i++)
//     {
//         for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> pascal(n);
    for(int i=0;i<pascal.size();i++)
    {
        pascal[i].resize(i+1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(j==0 || i==j) pascal[i][j]=1;
            else pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    return pascal;
}
int main()
{
    int n;
    cout<<"Enter the number of rows of Pascal Triangle : ";
    cin>>n;
    vector<vector<int>> ans;
    ans=pascalTriangle(n);
    cout<<"Printing the desired Pascal triangle :"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;
// int fact(int n)
// {
//     if(n==0 || n==1) return 1;
//     else return n*fact(n-1);
// }
// int C(int n,int r)
// {
//     return fact(n)/(fact(r)*fact(n-r));
// }
// vector<vector<int>> pascalTriangle(int n)
// {
//     vector<vector<int>> pascal(n);
//     for(int i=0;i<pascal.size();i++)
//     {
//         pascal[i].resize(i+1);
//     }
//     for(int i=0;i<pascal.size();i++)
//     {
//         for(int j=0;j<pascal[i].size();j++) pascal[i][j]=C(i,j);
//     }
//     return pascal;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<vector<int>> ans;
//     ans=pascalTriangle(n);
//     for(int i=0;i<ans.size();i++)
//     {
//         for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }