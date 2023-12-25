// Iterator -> iterate through STL containers
// Time Complexity: O(logn) for insertion and traversal in Set
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s={6,2,4,5,2};  //By default: Increasing Ordered Set
    s.insert(9);    // return an iterator to the inserted value
    s.insert(8);
    for(int i:s) cout<<i<<" ";
    cout<<endl;
    cout<<s.size()<<endl;
    s.insert(8); // size remains same because duplicate value is there, and set contains only unique values.
    cout<<s.size()<<endl;

    for(auto itr=s.begin();itr!=s.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;

    set<int,greater<int>> set1={6,53,6,35};  // Declaration of Decreasing ordered set
    set1.insert(48);
    set1.insert(53);
    for(auto i:set1) cout<<i<<" ";
    cout<<endl;
    cout<<set1.size()<<endl;
    set<int>::iterator itr;
    for(itr=set1.begin();itr!=set1.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    set<int> set2;
    set2.insert(1);
    set2.insert(3);
    set2.insert(4);
    set2.insert(3);
    set<int>::iterator it;
    for(it=set2.begin();it!=set2.end();it++)
    {
        cout<<*it<<" ";
    }
    // for(itr:set2)
    // {
    //     cout<<*itr<<" ";
    // }
}