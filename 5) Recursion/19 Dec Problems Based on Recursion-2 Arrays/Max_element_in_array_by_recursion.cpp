#include<iostream>
using namespace std;
int maxArray(int arr[],int i,int n)
{
    if(i==n) return INT_MIN;
    return max(arr[i],maxArray(arr,i+1,n));
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    int max=maxArray(arr,i,n);
    cout<<"Max element is : "<<max<<endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// int maxArray(int arr[],int n)
// {
//     if(n==0) return INT_MIN;
//     return max(arr[n-1],maxArray(arr,n-1));
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int max=maxArray(arr,n);
//     cout<<"Max element is: "<<max<<endl;
//     return 0;
// }