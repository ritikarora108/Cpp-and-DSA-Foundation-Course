#include<iostream>
using namespace std;
int binary(int decimal)
{
    if(decimal==0 || decimal==1) return decimal;
    return binary(decimal/2)*10 + (decimal)%2;
}
int main()
{
    int decimal;
    cin>>decimal;
    int ans=binary(decimal);
    cout<<ans<<endl;
    return 0;
}