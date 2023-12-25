// Pop(dequeue) efficient: Push->O(n)
//                          Pop->O(1)         Time Complexity
//                          front->O(1)
#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s;
    public:
    Queue(){}
    void enqueue(int val)
    {
        stack<int> temp;
        while(!s.empty())
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
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return;
        }
        s.pop();
    }
    bool isEmpty()
    {
        return s.size()==0;
    }
    int front()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return s.top();
    }
    int size()
    {
        return s.size();
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    while(!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}