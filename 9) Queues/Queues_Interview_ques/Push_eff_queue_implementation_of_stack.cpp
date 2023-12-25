// Push Efficient->   Push-> O(1)
//                    Pop-> O(n)   Time Complexity
//                    Top-> O(n)
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q;
    public:
    Stack(){}
    void push(int val)
    {
        q.push(val);
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return;
        }
        queue<int> temp;
        while(q.size()!=1)
        {
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
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
        queue<int> temp;
        while(q.size()!=1)
        {
            temp.push(q.front());
            q.pop();
        }
        int ans=q.front();
        temp.push(ans);
        q.pop();
        while(!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        return ans;
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