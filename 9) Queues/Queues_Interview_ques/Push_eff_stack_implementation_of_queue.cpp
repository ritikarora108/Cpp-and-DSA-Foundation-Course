// Push(enqueue) efficient: Push->O(1)
//                          Pop->O(n)         Time Complexity
//                          front->O(n)
#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s;
    public:
    Queue(){}
    void enqueue(int val)
    {
        s.push(val);
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return ;
        }
        stack<int> temp;
        while(s.size()!=1)
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
        stack<int> temp;
        while(s.size()!=1)
        {
            temp.push(s.top());
            s.pop();
        }
        int ans=s.top();
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
        return ans;
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