#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,5,7,9,87};
    int memoryAllocated =sizeof(arr);
    int length= memoryAllocated/sizeof(arr[0]);
    cout<<"Memory Allocated to arr : "<<memoryAllocated<<" bytes"<<endl;
    cout<<"length of arr :"<<length<<endl;


    char vowels[5];
    for(int i=0;i<5;i++) cin>>vowels[i];
    for(char ele:vowels) cout<<ele<<"\t"; //For each loop(traverses the loop from 0th to (size-1)th index by default)

    return 0;
}