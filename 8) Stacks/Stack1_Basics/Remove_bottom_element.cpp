#include<iostream>
#include<stack>
using namespace std;
void removeBottomElement(stack<int> &s)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    temp.pop();
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void f(stack<int> &s) // Function to remove last element
{
    if(s.size()==1)
    {
        s.pop();
        return;
    }
    int curr=s.top();
    s.pop();
    f(s);
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
    removeBottomElement(s);
    cout<<"Removing bottom iteratively: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    stack<int> p;
    p.push(11);
    p.push(12);
    p.push(13);
    cout<<"Removing bottom recursively: "<<endl;
    f(p);
    while(!p.empty())
    {
        cout<<p.top()<<endl;
        p.pop();
    }
}