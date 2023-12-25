//           1    2   3    4    5
//    ^      ^                  ^      ^
//    |      |                  |      |
//  rend   begin              rbegin  end

// rbegin() returns iterator to first element of set in reverse order
// rend() return iterator to position after last element of set in reverse order
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;      //-> Dynamic Size
    cout<<s.size()<<endl;         //Gives actual size of container s
    cout<<s.max_size()<<endl;  // maximum number of elements set can hold
                               // when size approaches to maxSize ,  maxSize updates and have a larger value
    cout<<s.empty()<<endl;
    s.insert(4);
    s.insert(5);
    cout<<s.empty()<<endl;       //Tells whether the set is empty or not
    s.clear();              // Removes all elements from set
    cout<<s.empty()<<endl;

    s.insert(5);
    s.insert(7);
    s.insert(3);
    auto itr=s.find(3);         // return iterator to the given value if present,  else return s.end()
    if(itr==s.end()) cout<<"3 not present"<<endl;
    else cout<<*itr<<endl;
    auto itr1=s.find(4);
    if(itr1==s.end()) cout<<"4 not present"<<endl;
    else cout<<*itr1<<endl;

    s.insert(3);
    s.insert(3);
    cout<<s.count(3)<<endl;         //gives 1 if element present else returns 0;
    cout<<s.count(8)<<endl;

    for(auto i:s) cout<<i<<" ";
    cout<<endl;

    cout<<*(s.lower_bound(6))<<endl;   // returns the iterator pointing to value
    cout<<*(s.lower_bound(5))<<endl;   // equal to it or just greater than it

    cout<<*(s.lower_bound(8))<<endl;   // if(value> value at last element) ->it returns the itr=s.begin()
    

    s.insert(0);
    s.insert(45);
    s.insert(36);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    cout<<*(s.upper_bound(36))<<endl;   // returns the iterator pointing to next
    cout<<*(s.upper_bound(35))<<endl;   // value greater than it

    cout<<*(s.upper_bound(45))<<endl;  // gives the random value beacuse 45 was last element
}