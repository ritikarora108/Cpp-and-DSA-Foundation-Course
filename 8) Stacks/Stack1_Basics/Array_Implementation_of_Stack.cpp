#include<iostream>
using namespace std;
class Stack{
    int *arr;
    int capacity;
    int top_index;
    public:
    Stack(int c)
    {
        this->capacity=c;
        arr=new int[c];
        this->top_index=-1;
    }
    void push(int data)
    {
        if(this->top_index==this->capacity-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        this->top_index++;
        this->arr[this->top_index]=data;
    }
    void pop()
    {
        if(this->top_index==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        this->top_index--;
    }
    bool isEmpty()
    {
        return (this->top_index==-1);
    }
    bool isFull()
    {
        return (this->top_index+1==this->capacity);
    }
    int top()
    {
        if(this->top_index==-1)
        {
            cout<<"Underflow"<<"\t";
            return INT_MIN;
        }
        return this->arr[this->top_index];
    }
    int size()
    {
        return this->top_index+1;
    }
};
int main()
{
    Stack s(10);
    for(int i=0;i<8;i++)
    {
        s.push(1+i);
    }
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    return 0;
}