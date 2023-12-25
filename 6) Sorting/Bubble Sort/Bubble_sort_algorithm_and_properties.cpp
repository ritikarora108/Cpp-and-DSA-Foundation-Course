// Bubble Sort Algorithm ( Stable Algorithm ):-
//Repeatedly swap two "adjacent" elements if in wrong order.

// Maximum Number of swaps in worst case in Bubble Sort: n*(n-1)/2
// Time Complexity in Worst Case : O(n^2)
// Space Complexity : O(1)

// Stable: Does not disturb the order of elements with same value
#include<iostream>
using namespace std;
void bubbleSort(int *arr,int n)
{
    for(int i=1;i<=n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<=n-i-1;j++) 
        {
            if(arr[j]>arr[j+1]) 
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break; // optimised solution for nearly sorted arrays
    }
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}