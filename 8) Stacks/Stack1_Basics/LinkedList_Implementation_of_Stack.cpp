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
class Stack{
    Node *head;
    int capacity;
    int currSize;
    public:
    Stack(int c)
    {
        this->capacity=c;
        this->head=NULL;
        this->currSize=0;
    }
    bool isEmpty()
    {
        return (this->head==NULL);
    }
    bool isFull()
    {
        return (this->capacity==this->currSize);
    }
    void push(int data)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        Node *newNode=new Node(data);
        newNode->next=this->head;
        this->head=newNode;
        this->currSize++;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node *newHead=this->head->next;
        this->head->next=NULL;
        delete this->head;
        this->head=newHead;
        currSize--;
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"Underflow \t ";
            return INT_MIN;
        }
        return this->head->data;
    }
    int size()
    {
        return this->currSize;
    }
};
int main()
{
    Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    s.push(4);
    s.push(5);
    s.push(8);
    cout<<s.top()<<endl;
    s.push(9);
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
}