// Time Complexity: O(n)
// Space Complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;
stack<int> reverse(stack<int> &s)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    return temp;
}
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    stack<int> s1=reverse(s);
    print(s1);
    stack<int> s2=reverse(s1);
    print(s2);
    s=reverse(s2);
    print(s);
}