// List is a template class in STL used to implement Doubly Linked List
// rbegin() points to first elemnet of list in reverse order
// rend() points to location after last element in reverse order
#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l={4,5,2,6}; // Initialise
    list<int>::iterator i;            // Iterator
    for(i=l.begin();i!=l.end();i++) cout<<*i<<" ";       //Traversal
    cout<<endl;
    for(auto j:l) cout<<j<<" ";   // auto
    cout<<endl;
    cout<<*(l.rbegin())<<endl;
    auto itr=l.end();
    advance(itr,1);           //advance function
    cout<<*itr<<endl;

    for(auto itr1=l.rbegin();itr1!=l.rend();itr1++) cout<<*itr1<<" ";     //Back traversal
    cout<<endl;

    auto ptr=l.begin();
    ptr++;
    ptr++;
    l.insert(ptr,3);                    //list_name.insert(itr,val) -> inserts value at a location before itr
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    l.insert(ptr,4,9);      // list_name.insert(itr,count,val)->insert val : count times before itr
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    auto start=l.begin();
    start++;
    auto end=l.begin();
    advance(end,6);
    l.insert(ptr,start,end);  // insert values from start to end(exclusive) before ptr
    for(auto k:l) cout<<k<<" ";
    cout<<endl;

    auto iter=l.begin();
    iter++;
    l.erase(iter);                   // erase element present at pointing iterator
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    start=l.begin();
    advance(start,2);
    end=l.begin();
    advance(end,10);
    l.erase(start,end);             // erase elements from start to end(exclusive)
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    

    l.pop_front();
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    l.push_front(7);
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    l.pop_back();
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    l.pop_back();
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    l.push_back(10);
    for(auto k:l) cout<<k<<" ";
    cout<<endl;
    return 0;
}