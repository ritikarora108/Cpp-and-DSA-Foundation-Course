#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Deque{
    Node *head;
    Node *tail;
    int size;
    public:
    Deque()
    {
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    void push_back(int val)
    {
        this->size++;
        Node *newNode=new Node(val);
        if(this->head==NULL)
        {
            this->head=this->tail=newNode;
            return;
        }
        this->tail->next=newNode;
        newNode->prev=this->tail;
        this->tail=newNode;
    }
    void push_front(int val)
    {
        this->size++;
        Node *newNode=new Node(val);
        if(this->head==NULL)
        {
            this->head=this->tail=newNode;
            return;
        }
        newNode->next=this->head;
        this->head->prev=newNode;
        this->head=newNode;        
    }
    void pop_front()
    {
        if(this->size==0)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        this->size--;
        Node *newHead=this->head->next;
        this->head->next=NULL;
        newHead->prev=NULL;
        delete this->head;
        this->head=newHead;
    }
    void pop_back()
    {
        if(this->size==0)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        this->size--;
        Node *newTail=this->tail->prev;
        this->tail->prev=NULL;
        newTail->next=NULL;
        delete this->tail;
        this->tail=newTail;
    }
    bool isEmpty()
    {
        return (this->size==0);
    }
    int front()
    {
        if(this->size==0) 
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return this->head->data;
    }
    int back()
    {
        if(this->size==0) 
        {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return this->tail->data;
    }
    int getSize()
    {
        return this->size;
    }
};
int main()
{
    Deque q;
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_front(0);
    q.push_front(33);
    while(!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    return 0;
}