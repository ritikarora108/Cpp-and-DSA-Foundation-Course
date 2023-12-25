// Pop Efficient->   Push-> O(n)
//                    Pop-> O(1)   Time Complexity
//                    Top-> O(1)
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q;
    public:
    Stack(){}
    void push(int val)
    {
        queue<int> temp;
        while(!q.empty())
        {
            temp.push(q.front());
            q.pop();
        }
        q.push(val);
        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return;
        }
        q.pop();
    }
    bool isEmpty()
    {
        return q.size()==0;
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return q.front();
    }
    int size()
    {
        return q.size();
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}