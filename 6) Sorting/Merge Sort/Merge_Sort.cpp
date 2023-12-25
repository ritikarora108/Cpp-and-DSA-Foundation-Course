// Merge Sort is Stable Srting Algorithm
// Applications : Used to sort large data sets.
// Limitations: Slower for Smaller tasks
//              O(n) extra space
//              Goes through whole process even if the array is sorted

//Space Complexity : O(n)  // temporary arrays
                           // Recursive stack( O(logn) )
//Time Complexity : O(nlogn).

#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int asize=(mid-l+1);
    int bsize=r-mid;
    int a[asize],b[bsize];
    for(int i=0;i<asize;i++) a[i]=arr[i+l];
    for(int j=0;j<bsize;j++) b[j]=arr[j+mid+1];
    int i=0,j=0; // initial index of array a and array b
    int idx=l; // initial index of merged subArray
    while(i<asize && j<bsize)
    {
        if(a[i]<=b[j]) arr[idx++]=a[i++];
        else arr[idx++]=b[j++];
    }
    while(i<asize) arr[idx++]=a[i++];
    while(j<bsize) arr[idx++] = b[j++];
}
void mergeSort(int arr[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"Printing the array after Merge Sort: "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}