#include<iostream>
#include<vector>
using namespace std;
class Queue{
    int front_idx;
    int back_idx;
    vector<int> v;
    public:
    Queue()
    {
        this->front_idx=-1;
        this->back_idx=-1;
    }
    void enqueue(int val)
    {
        if(front_idx==-1) front_idx=0;
        v.push_back(val);
        back_idx++;
    }
    void dequeue()
    {
        if(front_idx==-1) 
        {
            cout<<"Underflow"<<endl;
            return;
        }
        front_idx++;
        if(front_idx>back_idx)
        {
            front_idx=back_idx=-1;
            v.clear();
        }
    }
    bool isEmpty()
    {
        return (front_idx==-1);
    }
    int front()
    {
        if(front_idx==-1)
        {
            cout<<"Underflow"<<" ";
            return INT_MIN;
        }
        return v[front_idx];
    }
    int size()
    {
        if(front_idx==-1) return 0;
        return back_idx-front_idx+1;
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
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(400);
    q.enqueue(500);
    while(!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}