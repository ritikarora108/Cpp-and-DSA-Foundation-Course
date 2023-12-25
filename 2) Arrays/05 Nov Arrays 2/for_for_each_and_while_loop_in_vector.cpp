#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    for(int i=0;i<5;i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }

    // vector<int> v(5);
    // for(int i=0;i<5;i++)
    // {
    //     cin>>v[i];
    // }
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    cout<<"Printing via for loop: "<<endl;
    //for loop
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //for each loop
    cout<<"Printing via for each loop : "<<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //while loop
    cout<<"Printing via while loop:"<<endl;
    int i=0;
    while(i<v.size())
    {
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}