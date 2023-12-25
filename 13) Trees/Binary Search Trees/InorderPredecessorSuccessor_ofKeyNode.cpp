// Time Complexity: O(logn)
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
Node *inorderPredecessor(Node *root)
{
    
    root=root->left;
    if(root==NULL) return NULL;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
Node *inorderSuccessor(Node *root)
{
    
    root=root->right;
    if(root==NULL) return NULL;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
pair<Node*,Node*> inorderPredecessorSuccessor(Node *root,Node *key)
{
    if(root==NULL) return{NULL,NULL};
    Node *inpre=NULL;
    Node *insucc=NULL;
    while(root->val!=key->val)
    {
        if(root->val > key->val)
        {
            insucc=root;
            root=root->left;
        }
        else{
            inpre=root;
            root=root->right;
        }
    }
    Node *a=inorderPredecessor(root);
    Node *b=inorderSuccessor(root);
    if(a) inpre=a;
    if(b) insucc=b;
    return {inpre,insucc};
}
int main()
{
    BST bst;
    bst.root=insert(bst.root,4);
    bst.root=insert(bst.root,2);
    bst.root=insert(bst.root,6);
    bst.root=insert(bst.root,1);
    bst.root=insert(bst.root,3);
    bst.root=insert(bst.root,5);
    bst.root=insert(bst.root,7);
    inorder(bst.root);
    cout<<endl;
    int key;
    cout<<"Enter key:";
    cin>>key;
    pair<Node*,Node*> relative=inorderPredecessorSuccessor(bst.root,new Node(key));
    cout<<"Inorder Predecessor : "<<relative.first->val;
    cout<<endl<<"Inorder Successor: "<<relative.second->val<<endl;
    return 0;
}