#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{

    string s3;
    getline(cin,s3);
    cout<<s3<<endl;

    string s1="college";
    string s2("wallah");
    cout<<s1<<" "<<s2<<endl;

    string s4="ritikarora";
    reverse(s4.begin(),s4.end());
    cout<<s4<<endl;                // O(s4.length())

    string s5="apple";
    reverse(s5.begin()+2,s5.begin()+4);
    cout<<s5<<endl;

    string s6="helloworld";
    cout<<s6.substr(2,6)<<endl; // O(length)
    string temp=s6.substr(4);
    cout<<temp<<endl;

    string s7="hi";
    string s8("bro");
    s7+=s8;
    cout<<s7<<endl;

    char ch1[10]="orange";
    char ch2[10]="mango";
    strcat(ch1,ch2);
    cout<<ch1<<endl;

    string s9="abcd";
    char ch='e';
    s9.push_back(ch);
    cout<<s9<<endl;

    string s10="heybaby";
    cout<<s10.size()<<endl;    //O(1)
    cout<<s10.length()<<endl;  //O(1)

    char ch3[50]="watermelon";
    cout<<strlen(ch3)<<endl;   //O(n)

    int n=343;
    string s11=to_string(n);
    cout<<s11<<endl;
}