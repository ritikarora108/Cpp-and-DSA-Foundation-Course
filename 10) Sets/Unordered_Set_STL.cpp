// Unordered Set: _ values are stored in some random order based upon HashFunction (implemented through Hashing)
// Insertion       |
// Deletion        |->  O(1) average time complexity
// Traversal      _|
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(1);
    s.insert(32);
    s.insert(3);
    s.insert(45);
    s.insert(20);
    s.insert(56);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
}