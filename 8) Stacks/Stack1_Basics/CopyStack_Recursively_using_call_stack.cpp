#include<iostream>
#include<stack>
using namespace std;
void copyStack(stack<int> s,stack<int> &result)
{
    //Base case
    if(s.empty()) return;

    int currElement=s.top();
    s.pop();
    copyStack(s,result);
    result.push(currElement);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> result;
    copyStack(s,result);
    while(!result.empty())
    {
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}