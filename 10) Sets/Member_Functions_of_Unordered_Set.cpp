/* Member Functions of Unordered_Set:
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
5) size,max_size,clear,empty

                                                   Hash Table
                                                    ______
6) load_factor()= { size of unordered_set}         |______|    
                  { _____________________}         |______|   ---->bucket_count=3;
                  {      bucket_count    }         |______|
  
7) rehash(x)  : Set the Number of buckets to x or more by implementing new Hash Function ->O(N):avg, O(N^2) worst Case
*/
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
   unordered_set<int> s;
   s.insert(1);
   s.insert(2);
   s.insert(3);
   s.insert(4);
   for(auto i:s) cout<<i<<" ";
   cout<<endl;
   s.erase(2);
   for(auto i:s) cout<<i<<" ";
   cout<<endl;
   auto itr=s.begin();
   itr++;
   s.erase(itr);
   for(auto i:s) cout<<i<<" ";
   cout<<endl;
   s.insert(4);
   s.insert(5);
   s.insert(0);
   for(auto i:s) cout<<i<<" ";
   cout<<endl;
   auto j=s.begin();
   advance(j,3);
   s.erase(s.begin(),j);
   for(auto i:s) cout<<i<<" ";
   cout<<endl;
   cout<<s.size()<<endl;
   cout<<s.max_size()<<endl;
   cout<<s.empty()<<endl;
   s.clear();
   s.insert(1);
   s.insert(2);
   s.insert(4);
   s.insert(4);
   cout<<(s.count(2))<<endl;
   cout<<*(s.find(2))<<endl;
   cout<<s.load_factor()<<endl;
   cout<<s.bucket_count()<<endl;
   cout<<1.0*s.size()/s.bucket_count()<<endl;
   double x=s.size();
   double y=s.bucket_count();
   double a=x/y;
   cout<<a<<endl;
   if(s.load_factor()==a) cout<<"Yes";

   s.rehash(20);
   cout<<s.load_factor()<<endl;
   cout<<s.bucket_count();
}