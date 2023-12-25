#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s,int x)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void f(stack<int> &s,int x)
{
    if(s.empty()) 
    {
        s.push(x);
        return;
    }
    int curr=s.top();
    s.pop();
    f(s,x);
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
    int x=10;
    insertAtBottom(s,x);
    cout<<"Iteratively for stack s: ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    stack<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    f(p,100);
    cout<<"Recursively for stack p using call stack: ";
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
} 