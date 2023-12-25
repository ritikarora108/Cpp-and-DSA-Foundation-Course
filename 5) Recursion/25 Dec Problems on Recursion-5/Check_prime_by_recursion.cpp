#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n,int i)
{
    if(n<0) 
    {
        cout<<"Enter a valid Natural number"<<endl;
        return 0;
    }
    if(i>=sqrt(n)+1) return 1;
    if(n%i==0) return 0;
    if(isPrime(n,i+1)) return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    if(isPrime(n,2)) cout<<"Prime"<<endl;
    else cout<<"Not prime"<<endl;
    return 0;
}