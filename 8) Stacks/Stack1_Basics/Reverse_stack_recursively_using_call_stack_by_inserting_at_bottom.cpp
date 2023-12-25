// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s,int val)
{
    if(s.empty())
    {
        s.push(val);
        return;
    }
    int curr=s.top();
    s.pop();
    insertAtBottom(s,val);
    s.push(curr);
}
void reverse(stack<int> &s)
{
    if(s.empty()) return;
    int curr=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,curr);
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

    reverse(s);
    print(s);
    return 0;
}