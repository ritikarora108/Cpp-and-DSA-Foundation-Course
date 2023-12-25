// Armstrong Number of Four Digits : 1634 i.e 1^4+6^4+3^4+4^4 = 1634
// Armstrong Number of Three Digits : 153 i.e. 1^3+5^3+3^3=153
#include<iostream>
using namespace std;
int power(int p,int q)
{
    if(q==0) return 1;
    int ans=power(p,q/2);
    if(q%2==0) return ans*ans;
    else return ans*ans*p;
}
int f(int n,int d)
{
    if(n==0) return 0;
    return f(n/10,d)+power(n%10,d);
}
int main()
{
    int n;
    cin>>n;
    int m=n;
    int d=0;
    while(m>0)
    {
        d++;
        m/=10;
    }
    if(n==f(n,d)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
    //Below Solution is specifically for 100<=n<=999
}

// #include<iostream>
// #include<math.h>
// using namespace std;
// int f(int n) // returns sum of cube of digits
// {
//     if(n==0) return 0;
//     return f(n/10)+pow(n%10,3);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     if(n==f(n)) cout<<"Yes, it is an armstrong number"<<endl;
//     else cout<<"No, it is not an armstrong number"<<endl;
//     return 0;
// }


