//Euclid's Algorithm
#include<iostream>
using namespace std;

//via Modulo operator
int gcd(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;
    else if(a>b) return gcd(a%b,b);
    else return gcd(a,b%a);
}

//Modulo-2
// int gcd(int a,int b)
// {
//     if(b>a) return gcd(b,a);
//     if(b==0) return a;
//     return gcd(b,a%b);
// }

//via subtraction operator 

// int gcd(int a,int b)
// {
//     if(a==0) return b;
//     if(b==0) return a;
//     if(a==1 || b==1) return 1;
//     if(a==b) return a;
//     else if(a>b) return gcd(a-b,b);
//     else return gcd(a,b-a);
// }

int main()
{
    int a,b;
    cout<<"Enter : "<<endl;
    cin>>a>>b;
    int hcf=gcd(a,b);
    cout<<hcf<<endl;
    return 0;
}