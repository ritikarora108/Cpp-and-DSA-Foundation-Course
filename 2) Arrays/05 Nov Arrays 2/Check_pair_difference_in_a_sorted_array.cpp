// Given a vector arr[] sorted in increasing order. Return an array of squares of each
// number sorted in increasing order. Where size of vector 1<size<101.

// Input: [5,10,15,20,26] x= 10
// Output: Yes

// Input: [5,6,7,8,9] x=4
// Output : Yes

// Input: [9,23,45,69,78] x=56
// Output :No

#include<iostream>
using namespace std;
bool check_difference_pair(int arr[],int n,int x)
{
    int i=0,j=1;
    while(j<n)
    {
        int diff=arr[j]-arr[i];
        if(diff==x) return 1;
        else if(diff>x){
            i++;
            j++;
        }
        else j++;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int difference;
    cin>>difference;
    if(check_difference_pair(arr,n,difference)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}