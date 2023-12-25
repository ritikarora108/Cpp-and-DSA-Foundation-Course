#include<iostream>
using namespace std;
int main()
{
    int array[6];
    for(int &element : array) cin>>element;
    for(int element : array) cout<<element<<" ";
    return 0;
}