#include<iostream>
//#include<cstring>
using namespace std;
int main()
{
    string s="hello world!";
    char *ptr=&s[0];
    ptr+=4;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
}