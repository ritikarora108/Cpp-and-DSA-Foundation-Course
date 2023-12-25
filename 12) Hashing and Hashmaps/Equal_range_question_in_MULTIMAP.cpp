#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    multimap<int,int> m;
    m.insert({1,1});
    m.insert({2,4});
    m.insert({3,9});
    m.insert({4,16});
    m.insert({4,20});
    auto a=m.equal_range(4);     // auto -> pair<start_itr,end_itr>  
    //  start itr points to first occ. of key and end_itr points to pos after last element of key
    for(auto it=a.first;it!=a.second;it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}