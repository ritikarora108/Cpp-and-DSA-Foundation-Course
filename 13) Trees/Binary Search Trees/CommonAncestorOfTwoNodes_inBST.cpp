// Time Complexity : O(logn)
// Space Complexity : O(logn)
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->val=d;
        this->left=this->right=NULL;
    }
};
class BST{
    public:
    Node *root;
    BST()
    {
        this->root=NULL;
    }
};
Node *insert(Node *&root,int key)
{
    if(root==NULL) return new Node(key);
    if(root->val > key)
    {
        root->left=insert(root->left,key);
    }
    else root->right=insert(root->right,key);
    return root;
}
void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
Node *lowestCommonAncestor(Node *root,Node *p,Node *q)
{
    if(p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left,p,q);
    }
    else if(p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
}
int main()
{
    BST bst;
    bst.root=insert(bst.root,8);
    bst.root=insert(bst.root,3);
    bst.root=insert(bst.root,10);
    bst.root=insert(bst.root,1);
    bst.root=insert(bst.root,6);
    bst.root=insert(bst.root,14);
    bst.root=insert(bst.root,4);
    bst.root=insert(bst.root,7);
    bst.root=insert(bst.root,13);
    inorder(bst.root);
    cout<<endl;
    cout<<lowestCommonAncestor(bst.root,new Node(1),new Node(7))->val;
}