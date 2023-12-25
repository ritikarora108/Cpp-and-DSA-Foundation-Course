// Time complexity for deletion: O(logn) for -> set_name.erase(value);  and   set_name.erase(position)
//                     Deletion : O(n)    for -> set_name.erase(pos1,pos2) -> delete elements from pos1 to pos2(excluded); 
#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(6);
    s.insert(9);
    s.insert(0);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    set<int>:: iterator itr;
    for(itr=s.begin();itr!=s.end();itr++) cout<<*itr<<" ";
    cout<<endl;
    s.erase(2);                                                    //set_name.erase(value);
    for(itr=s.begin();itr!=s.end();itr++) cout<<*itr<<" ";
    cout<<endl;
    itr=s.begin();
    itr++;
    s.erase(itr);                                                 //set_name.erase(position)
    for(itr=s.begin();itr!=s.end();itr++) cout<<*itr<<" ";
    cout<<endl;
    set<int>:: iterator itr2;
    itr=s.begin();
    itr2=s.begin();
    itr2++;
    itr2++;
    s.erase(itr,itr2);                                   // set_name.erase(pos1,pos2)->delete elements from pos1 to pos2-1
    for(itr=s.begin();itr!=s.end();itr++) cout<<*itr<<" ";
    cout<<endl;

    s.insert(5);
    s.insert(6);
    s.insert(63);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    auto iter=s.begin();
    advance(iter,3);     // takes iter 3 step froward i.e. to 4th location
    s.erase(iter);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
    auto j=s.begin();
    advance(j,3);
    s.erase(s.begin(),j);
    for(auto i:s) cout<<i<<" ";
    cout<<endl;
}