#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Hashing{
    vector<list<int>> HashTable;
    int buckets;
    public:
    Hashing(int size)
    {
        this->buckets=size;
        this->HashTable.resize(this->buckets);
    }
    int HashValue(int key)
    {
        return (key % this->buckets);   //Divivion Method
    }
    void insert(int key)
    {
        int i=HashValue(key);
        HashTable[i].push_back(key);
    }
    list<int>::iterator search(int key)
    {
        int i=HashValue(key);
        return find(HashTable[i].begin(),HashTable[i].end(),key);
    }
    void erase(int key)
    {
        int i=HashValue(key);
        if(HashTable[i].end()!=search(key))
        {
            HashTable[i].erase(search(key));
            
            cout<<key<<" is deleted"<<endl;
        }
        else cout<<key<<" was not present in HashTable"<<endl;
    }
};
int main()
{
    Hashing h(10);
    h.insert(445);
    h.insert(512);
    h.insert(629);
    h.insert(542);
    h.insert(1324);
    h.erase(542);
    h.erase(542);
    list<int>::iterator itr=h.search(1324);
    cout<<*itr<<endl;
}
