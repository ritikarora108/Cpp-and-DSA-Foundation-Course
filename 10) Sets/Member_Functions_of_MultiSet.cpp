/* Member Functions of MultiSet:
1)insert : O(logN)
2) deletion: erase(value) ->delete all instances of value                    -> O(logN)
             erase(itr) -> delete value at itr                               -> O(logN)
             erase(s_itr,e_itr) -> delete the range of elements               -> O(N)
3)find() -> point to lower_bound of value if present else return end_itr     -> O(logN)
4)count() -> give the no. of Ocuurances(say k) of the element                -> O(k+logN)
5)lower bound-> return itr pointing to first occ. of element else            -> O(logN)
                return itr pointing to val just greater than it
6) upper bound-> return itr pointing to next value greater than passed value -> O(logN)
*/
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(4);
    s.insert(5);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    s.erase(5);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    auto itr=s.begin();
    itr++;
    s.erase(itr);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    itr=s.begin();
    advance(itr,3);
    s.erase(s.begin(),itr);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(4);
    s.insert(5);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    cout<<s.count(5)<<endl;
    if(s.find(2)!=s.end()) cout<<"2 Present"<<endl;
    if(s.find(7)!=s.end()) cout<<"7 Present"<<endl;
    else cout<<"7 Not present"<<endl;

    cout<<*(s.lower_bound(3))<<endl;
    cout<<*(s.upper_bound(2))<<endl;
}