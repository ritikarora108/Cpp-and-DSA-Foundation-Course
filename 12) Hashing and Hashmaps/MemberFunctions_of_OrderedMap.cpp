// Member Functions:                                                                   inclusive  exclusive
// 1) Modifier   ->    insert : O(logn)                                                       |    |
//                     erase :  m.erase(value) : O(logn) , m.erase(itr) : O(logn) , m.erase(itr1,itr2) : O(n) 
//                     swap:   m1.swap(m2)   or swap(m1,m2)  if m1 & m2 has ame type of key value pairs
//                     clear:   m.clear  ->  erase all elements of map m

// 2)Capacity    ->   size : m.size() tell the size of map m
//                    max_size : max no. of elements that can be allocated to map, till further updation
//                    empty: m.empty() returns true if m is empty else false;

// 3) Operations  ->  find : m.find(key) : return itr to key in map if present else return m.end()
//                    count: m.count(key) : return count of key present in map.( either 0 or 1 : unique values)
//                    lower_bound : m.lower_bound(key) returns itr to key if present else to element just greater than key
//                    upper_bound  : m.upper_bound(key) return itr to elemnt just greater than key

// begin() , end()  , rbegin() , rend()
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int,greater<string>> m;    // decreasing order : functioning of upper_bound & lower_bound differs
                                         //                     to increasing order map
    m.insert({"ritik",1});
    m["div"]=4;
    m["jonas"]=45;
    m.insert(make_pair("marie",43));
    for(auto i:m)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    cout<<((m.upper_bound("marie"))->first)<<endl;
    cout<<(m.upper_bound("maya")->first)<<endl;

    cout<<((m.lower_bound("marie"))->first)<<endl;
    cout<<(m.lower_bound("maya")->first)<<endl;
    m.clear();
    cout<<m.size()<<" "<<m.max_size()<<" "<<m.empty();
}