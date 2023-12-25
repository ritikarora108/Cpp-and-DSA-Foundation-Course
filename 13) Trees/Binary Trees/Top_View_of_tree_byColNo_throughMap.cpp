// Given a binary Tree , print the top view of binaryTree, Top View of the
// binary tree is the set of nodes visible when the tree is viewed from the top.

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
vector<int> topProfile(Node *root)
{
    if(root==NULL) return {};
    queue<pair<Node*,int>> q;
    map<int,int> m; // {col,node->value}
    q.push({root,0});
    vector<int> ans;
    while(!q.empty())
    {
        pair<Node*,int> t=q.front();
        q.pop();
        Node *currNode=t.first;
        int currentCol=t.second;
        m.insert({currentCol,currNode->value});
        if(currNode->left) q.push({currNode->left,currentCol-1});
        if(currNode->right) q.push({currNode->right,currentCol+1});
    }
    for(auto pairs:m)
    {
        ans.push_back(pairs.second);
    }
    return ans;
}
int main()
{
    Node *root=new Node(2);                                   //     2
    root->left=new Node(4);                                   //   4   10
    root->right=new Node(10);                                 //  6 5     11
    root->left->left=new Node(6);                             //        12
    root->left->right=new Node(5);                            //          13
    root->right->right=new Node(11);                          //             14
    root->right->right->left=new Node(12);
    root->right->right->left->right=new Node(13);
    root->right->right->left->right->right=new Node(14);
    vector<int> topView = topProfile(root); // Taking first element of each column (by maps)

    for(int i:topView) cout<<i<<" ";
    cout<<endl; 
    return 0;
}