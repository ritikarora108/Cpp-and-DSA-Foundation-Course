#include<iostream>
using namespace std;
bool isSorted(int arr[],int i,int n)
{
    if(i==n) return 1;
    if(isSorted(arr,i+1,n)){
        if(arr[i-1]<arr[i]) return 1;
        return 0;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=1;
    if(isSorted(arr,i,n)) cout<<"Yes, the given array is sorted."<<endl;
    else cout<<"No, the given array is not sorted."<<endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// bool isSorted(int arr[],int n)
// {
//     if(n==1) return 1;
//     if(isSorted(arr,n-1))
//     {
//         if(arr[n-2]<arr[n-1]) return 1;
//         return 0;
//     }
//     return 0;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     cout<<isSorted(arr,n)<<endl;
//     return 0;
}