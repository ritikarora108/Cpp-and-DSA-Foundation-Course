#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};
class Queue{
    Node *head;
    Node *tail;
    int size;
    public:
    Queue()
    {
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    void enqueue(int val)
    {
        Node *newNode=new Node(val);
        size++;
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }
    void dequeue()
    {
        if(head==NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        size--;
        Node *newHead=head->next;
        head->next=NULL;
        delete head;
        head=newHead;
        if(head==NULL) tail=NULL;
    }
    bool isEmpty()
    {
        return size==0;
    }
    int front()
    {
        if(head==NULL)
        {
            cout<<"Underflow"<<" ";
            return INT_MIN;
        }
        return head->data;
    }
    int getSize()
    {
        return size;
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