#include<iostream>
#include<vector>
using namespace std;
class CircularQueue{
    vector<int> v;
    int cap;
    int front;
    int back;
    int size;
    public:
    CircularQueue(int n)
    {
        this->v.resize(n);
        this->cap=n;
        this->front=0;
        this->back=n-1;
        this->size=0;
    }
    void enqueue(int val)
    {
        if(isFull())
        {
            cout<<"Overflow"<<endl;
            return;
        }
        this->size++;
        back=(back+1) % cap;
        v[back]=val;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return;
        }
        this->size--;
        front=(front+1) % cap;
    }
    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==cap;
    }
    int getFront()
    {
        if(isEmpty())
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return v[front];
    }
    int getSize()
    {
        return size;
    }
};
int main()
{
    CircularQueue q(8);
    q.enqueue(20);
    q.enqueue(6);
    q.enqueue(40);
    q.enqueue(100);
    q.dequeue();
    q.enqueue(120);
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(200);
    while(!q.isEmpty())
    {
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    return 0;

}