/*Insertion Sort Algorithm (Stable Sorting Algorithm)
Repeatedly take the elements from unsorted subarray and place them at their correct position 
in sorted subarray

Applications of Insertion Sort: 
Better than selection sort in case of nearly sorted arrays

Worst Case Time Complexity: O(n^2) -> Quadratic
Best Case Time Complexity: Ω(n) -> Linear
Space Complexity : O(1) -> Constant

//Stable Sorting Algorithm: Do not disturb the order of elements having same value.
*/
#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int> &v)
{
    int n=v.size();
    //assuming array is divided in two parts sorted (v[0]) and unsorted (rest)
    for(int i=1;i<n;i++)
    {
        int current_ele=v[i];
        // inserting current element at its correct position
        int j=i-1;
        while(j>=0 && v[j]>current_ele)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current_ele;
    }
    //array has been sorted
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    insertionSort(v);
    for(int i:v) cout<<i<<" ";
    return 0;
}