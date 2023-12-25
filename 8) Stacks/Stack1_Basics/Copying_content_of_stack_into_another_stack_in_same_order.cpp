#include<iostream>
#include<stack>
using namespace std;
void reverseContent(stack<int> s1,stack<int> &s2)
{
    //Content of stack gets reversed
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void print(stack<int> st)
{
    int n=st.size();
    cout<<"-> From TOP:  ";
    for(int i=1;i<=n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<" :-> To Bottom";
    cout<<endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    stack<int> temp;
    reverseContent(s,temp);
    print(temp);
    stack<int> result;
    reverseContent(temp,result);
    print(result);
    return 0;
}