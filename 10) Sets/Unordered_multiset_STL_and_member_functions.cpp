/* Member Functions of unordered_multiset:
1) insertion(.insert()):    Single element   -> O(1) : avg case timme complexity
                                             -> O(N) : worst case time complexity {N is the size of unordered_set}
                                                (when size > capacity , it will reHash all the elements of set)
              Multiple elements  -> O(n) : avg case time complexity
                                 ->O(n*(N+1)) : {n=no. of elements to add, N=size of unordered_set}
                                                                        _
2) deletion(.erase()): erase(value)                           ->  O(1)   |         O(N)->worst case for all
                       erase(iterator)                        ->  O(1)   |-> avg case time complexity
                       erase(start_itr(itr1),end_itr(itr2))   ->  O(n)  _|

3) find() : O(1)->avg, O(N)->worst
4) count() : O(1)->avg, O(N)->worst
*/
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_multiset<int> ums;
    ums.insert(1);
    ums.insert(8);
    ums.insert(3);
    ums.insert(4);
    ums.insert(3);
    for(auto i:ums) cout<<i<<" ";
    cout<<endl;
    return 0;
}