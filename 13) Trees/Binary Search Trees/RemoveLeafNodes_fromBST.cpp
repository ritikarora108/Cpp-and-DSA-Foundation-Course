// Time Complexity: O(n)
// Space Complexity: O(logn)
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
void preorder(Node *root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node *removeLeafNodes(Node *root)
{
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}
int main()
{
    BST bst;
    bst.root=insert(bst.root,3);
    bst.root=insert(bst.root,1);
    bst.root=insert(bst.root,4);
    bst.root=insert(bst.root,2);
    bst.root=insert(bst.root,6);
    inorder(bst.root);
    cout<<endl;
    bst.root=removeLeafNodes(bst.root);
    inorder(bst.root);
    cout<<endl;
    preorder(bst.root);
}