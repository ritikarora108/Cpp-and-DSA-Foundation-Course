// Selection Sort Algorithm ( Unstable Algorithm ):-
// Ex: 3,4,3*,2
//  0) 2,4,3*,3
//  1) 2,3*,4,3
//  2) 2,3*,3,4 (Sorted, Order of 3* and 3 has been changed -> Unstable) 

//Repeatedly find min element aand place it in the beginning of unsorted array.
// (ith pass-> gives the element at ith index)

//Applications of Selection Sort: 
//(Better than Bubble Sort in some cases) 
//Max number of swaps in worst case in Selection Sort: n-1 -> O(n) as compared to O(n^2) in Bubble sort

// Maximum Number of comparisons in worst/best case in Selection Sort: n*(n-1)/2
// Time Complexity in Worst Case : O(n^2)
// Time Complexity in Best Case : Ω(n^2)
// Space Complexity : O(1)

// Unstable: May or may not disturb the order of elements with same value.

#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index=j;
            }
        }
        if(i!=min_index) swap(arr[i],arr[min_index]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    selectionSort(v);
    //Printing the sorted Array
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}