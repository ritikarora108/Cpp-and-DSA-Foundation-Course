#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int> ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(1);
    ms.insert(4);
    ms.insert(1);
    ms.insert(3);
    for(auto i:ms) cout<<i<<" ";
    cout<<endl;

    multiset<int,greater<int>> ms1;
    ms1.insert(31);
    ms1.insert(22);
    ms1.insert(11);
    ms1.insert(41);
    ms1.insert(11);
    ms1.insert(31);
    for(auto i:ms1) cout<<i<<" ";
    cout<<endl;
    return 0;
} 