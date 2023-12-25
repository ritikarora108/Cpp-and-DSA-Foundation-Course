// Map stores the data in ordered form of keys.
// It don't have duplicate value of key.
// It stores the key-value pair.
// Maps are implemented through Binary Search Tree(BST).

#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> directory;            // declaration
    directory["manan"]=2134;                  // insertion type 1
    directory["umesh"]=5356;
    directory.insert(make_pair("ritik",93844));     // insertion type 2
    directory.insert({"kavya",445});
    for(auto element : directory)   // auto -> key-value pair          // Traversal
    {
        string key=element.first;
        int num=element.second;
        cout<<key<<" -> "<<num<<endl;
    }
    cout<<endl;
    directory["umesh"]=11111;                                                   // it updates num at "umesh"
    directory.insert(make_pair("ritik",45404));                                 // No updation 
    for(auto element : directory)   
    {
        string key=element.first;
        int num=element.second;
        cout<<key<<" -> "<<num<<endl;
    }
    cout<<endl;
    
    return 0;
}