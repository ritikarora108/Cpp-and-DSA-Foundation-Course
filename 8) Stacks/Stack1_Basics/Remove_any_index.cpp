#include<iostream>
#include<stack>
using namespace std;
void removeIndex(stack<int> &s,int idx)
{
    stack<int> temp;
    int n=s.size();
    for(int i=1;i<=n-idx-1;i++)
    {
        temp.push(s.top());
        s.pop();
    }
    s.pop();
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void f(stack<int> &p,int idx)
{
    if(p.size()==idx+1)
    {
        p.pop();
        return;
    }
    int curr=p.top();
    p.pop();
    f(p,idx);
    p.push(curr);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int idx=3;
    removeIndex(s,idx);
    cout<<"Removing index iteratively: "<<endl;
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
    p.push(14);
    cout<<"Removing index recursively: "<<endl;
    int index=2;
    f(p,index);
    while(!p.empty())
    {
        cout<<p.top()<<endl;   
        p.pop();
    }
}