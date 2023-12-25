// Generic Trees (N-ary Tree): Every node has data and list of references to its children nodes
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    char val;
    vector<Node*> children;      // children.size()==0 -> leaf Node
    Node(char data)
    {
        this->val=data;
    }
};
int main()
{
    Node *root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));

    cout<<root->val<<endl;
    cout<<"Printing child nodes of "<<root->val<<" :"<<endl;
    for(Node* child:root->children)
    {
        cout<<child->val<<" ";
    }
    return 0;
}