#include<iostream>
using namespace std;
void printArray(int arr[],int i,int n)
{
    if(i==n) return;
    cout<<arr[i]<<" ";
    printArray(arr,i+1,n);
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: "<<endl;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    cout<<"Printing the array: "<<endl;
    printArray(arr,i,n);
    return 0;
}

// #include<iostream>
// using namespace std;
// void printArray(int arr[],int n)
// {
//     if(n==0) return;
//     printArray(arr,n-1);
//     cout<<arr[n-1]<<" ";
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     printArray(arr,n);
//     return 0;
// }