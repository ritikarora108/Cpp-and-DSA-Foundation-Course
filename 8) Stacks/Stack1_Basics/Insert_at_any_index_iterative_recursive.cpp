#include<iostream>
#include<stack>
using namespace std;
void insertAt(stack<int> &s,int idx,int val)
{
    stack<int> temp;
    int elementsToBeRemoved= s.size()-idx;
    for(int i=1;i<=elementsToBeRemoved;i++)
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(val);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void f(stack<int> &s,int idx,int val)
{
    if(s.size()<=idx)
    {
        s.push(val);
        return;
    }
    int curr=s.top();
    s.pop();
    f(s,idx,val);
    s.push(curr);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int idx=2;
    int val=7;
    cout<<"Inserting Iteratively: "<<endl;
    insertAt(s,idx,val);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;

    stack<int> p;
    p.push(11);
    p.push(20);
    p.push(32);
    p.push(43);
    p.push(55);
    int index=1;
    int value=76;
    f(p,index,value);
    cout<<"Inserting Recursively: "<<endl;
    while(!p.empty())
    {
        cout<<p.top()<<endl;
        p.pop();
    }
    cout<<endl;
    return 0;
}