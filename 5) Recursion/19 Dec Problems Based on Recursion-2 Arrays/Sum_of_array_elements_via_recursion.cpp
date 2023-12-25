#include<iostream>
using namespace std;
int sumArray(int arr[],int i,int n)
{
    if(i==n) return 0;
    return arr[i]+sumArray(arr,i+1,n);
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
    int sum=sumArray(arr,i,n);
    cout<<"Sum is: "<<sum<<endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// int sumArray(int arr[],int n)
// {
//     if(n==0) return 0;
//     return arr[n-1]+sumArray(arr,n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int sum=sumArray(arr,n);
//     cout<<"Sum is: "<<sum<<endl;
//     return 0;
// }