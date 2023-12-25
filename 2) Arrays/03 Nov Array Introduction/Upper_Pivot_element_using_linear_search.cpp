#include<iostream>
using namespace std;
int pivot(int arr[],int n)
{
    for(int i=1;i<(n-1);i++)
    {
        int flag=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[i])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) return arr[i];
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Required element is : "<<pivot(arr,n)<<endl;
    return 0;
}