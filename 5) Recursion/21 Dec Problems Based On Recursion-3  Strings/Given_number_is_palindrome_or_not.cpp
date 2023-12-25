#include<iostream>
using namespace std;
bool check_palindrome(int n,int &temp)
{
    if(n==0) return 1;
    if(check_palindrome(n/10,temp))
    {
        if(n%10==temp%10)
        {
            temp/=10;
            return 1;
        }
        return 0;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int temp=n;
    if(check_palindrome(n,temp)) cout<<n<<" is a palindrome"<<endl;
    else cout<<n<<" is not a palindrome"<<endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// bool check(int arr[],int i,int size)
// {
//     if(i==size) return 1;
//     if(check(arr,i+1,size))
//     {
//         if(arr[i]==arr[size-1-i]) return 1;
//         return 0;
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int m=n;
//     int arr[10];
//     int idx=0;
//     while(n>0)
//     {
//         arr[idx++]=n%10;
//         n/=10;
//     }
//     cout<<check(arr,0,idx)<<endl;
// }

// #include<iostream>
// using namespace std;
// bool check(string &s,int i)
// {
//     if(i==s.length()) return 1;
//     if(check(s,i+1))
//     {
//         if(s[i]==s[s.length()-1-i]) return 1;
//         else return 0;
//     }
//     return 0;
// }
// int main()
// {
//     string s;
//     cin>>s;
//     if(check(s,0)) cout<<"Yes,it is a palindrome"<<endl;
//     else cout<<"It is not a palindrome"<<endl;
//     return 0;
// }