#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"Size : "<<v.size()<<endl; //0
    cout<<"Capacity : "<<v.capacity()<<endl; //0

    v.push_back(1);
    cout<<"Size : "<<v.size()<<endl; //1
    cout<<"Capacity : "<<v.capacity()<<endl; //1

    v.push_back(2);
    cout<<"Size : "<<v.size()<<endl; //2
    cout<<"Capacity : "<<v.capacity()<<endl; //2

    v.push_back(3);
    cout<<"Size : "<<v.size()<<endl; //3
    cout<<"Capacity : "<<v.capacity()<<endl; //4

    v.resize(5);
    cout<<"Size : "<<v.size()<<endl; //5
    cout<<"Capacity : "<<v.capacity()<<endl; //8(generally, but compiler dependent)

    v.resize(10);
    cout<<"Size : "<<v.size()<<endl; //10
    cout<<"Capacity : "<<v.capacity()<<endl; //16(generally, but compiler dependent)

    v.pop_back();
    v.pop_back();
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.resize(11);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;
    return 0;
}