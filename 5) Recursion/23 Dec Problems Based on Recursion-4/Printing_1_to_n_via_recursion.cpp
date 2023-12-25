#include<iostream>
using namespace std;
void print(int n)
{
    if(n<1) return;
    print(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    cout<<"Printing natural numbers: "<<endl;
    print(n);
    return 0;
}

// #include<iostream>
// using namespace std;
// void print(int i,int n)
// {
//     if(i>n) return;
//     cout<<i<<" ";
//     print(i+1,n);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     print(1,n);
//     return 0;
// }