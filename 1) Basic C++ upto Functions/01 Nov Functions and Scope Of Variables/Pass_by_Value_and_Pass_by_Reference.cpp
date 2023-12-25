#include<iostream>
using namespace std;
void changeValue(int *z)
{
    *z=100;
}
float changeValue(float y)
{
    y=100.78;
    return y;
}
int main()
{
    int a=5;
    changeValue(&a);  // Pass by reference 
    cout<<a<<endl;

    float b=7;
    float x=changeValue(b);  // Pass by Value
    cout<<b<<endl;
    cout<<x<<endl;
    return 0;
}