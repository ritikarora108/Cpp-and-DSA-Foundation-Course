// #include<iostream>
// #include<vector>
// using namespace std;
// void setZeroesToEnd(vector<int> &v)
// {
//     int cnt=0;
//     for(int i=0;i<v.size();)
//     {
//         if(v[i]==0) 
//         {
//             cnt++;
//             v.erase(v.begin()+i);
//         }
//         else i++;
//     }
//     for(int i=0;i<cnt;i++)
//     {
//         v.insert(v.end(),0);
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];
//     setZeroesToEnd(v);
//     for(int i:v) cout<<i<<" ";
//     return 0;
// }

#include<iostream>
using namespace std;
void placeZeroesToEnd(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        bool swapped=false;
        for(int j=0;j<=n-i-1;j++)
        {
            if(arr[j]==0 && arr[j+1]!=0) 
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    placeZeroesToEnd(arr,n);
    print(arr,n);
    return 0;
}