//    Binary Code:  1   0   0   1   1   0
//                  |\ / \ / \ / \ / \ /
//                  | ^   ^   ^   ^   ^
//    Gray Code:    1 1   0   1   0   1

#include<iostream>
using namespace std;
int gray(int binary)
{
    if(binary==1) return 1;
    return gray(binary/10)*10 + ((binary/10)%10)^(binary%10);
}
int main()
{
    int binary;
    cin>>binary;
    cout<<gray(binary)<<endl;
    return 0;
} 