#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> q;
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_front(0);
    q.push_front(33);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
}