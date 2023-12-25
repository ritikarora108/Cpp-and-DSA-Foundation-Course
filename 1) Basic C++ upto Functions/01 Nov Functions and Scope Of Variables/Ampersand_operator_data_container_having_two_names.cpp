#include<iostream>
using namespace std;
int main()
{
    int p=7;
    int &q=p;
    cout<<p<<endl;
    cout<<q<<endl;
    cout<<&p<<endl; // address of p and q are same i.e a data container having value 7 and name p as well as q
    cout<<&q<<endl;
    return 0;
}