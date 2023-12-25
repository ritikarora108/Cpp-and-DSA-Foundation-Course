//Space Complexity : O(n) i.e. n Stack Frames formed in the Call Stack.
//Time Complexity : O(n) ; T= (Number of stack frames)*(The time consumed in one single function call)
//                           = n.c; c=constant   --> T=O(n).

#include<iostream>
using namespace std;
int Factorial_calculation_recursively(int n)
{
    if(n==0 || n==1) return 1;
    else return n*Factorial_calculation_recursively(n-1);
}
int main()
{
    //int n;
    //cin>>n;
    cout<<Factorial_calculation_recursively(6)<<endl;
    return 0;
}