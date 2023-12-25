// Given the root of a binary tree , return all the leaf nodes present in it/
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->value=data;
        this->left=this->right=NULL;
    }
};
vector<int> leafNodes(Node* root)
{
    if(root==NULL) return {};
    if(root->left==NULL && root->right==NULL ) return {root->value};

    vector<int> l=leafNodes(root->left);
    vector<int> r=leafNodes(root->right);
    vector<int>  ans;
    if(l.size()) ans.insert(ans.end(),l.begin(),l.end());
    if(r.size()) ans.insert(ans.end(),r.begin(),r.end());
    return ans;
}
int main()
{
    Node *root=new Node(2);                                   //     2
    root->left=new Node(4);                                   //   4   10
    root->right=new Node(10);                                 //  6 5     11
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    vector<int> leafs = leafNodes(root);
    for(int i:leafs) cout<<i<<" ";
    return 0;
}