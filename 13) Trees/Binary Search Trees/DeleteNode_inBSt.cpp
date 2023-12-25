#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
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
void insert(Node *&root,int key)
{
    if(root==NULL)
    {
        root=new Node(key);
        return;
    }
    Node *currNode=root;
    while(true)
    {
        if(currNode->val > key)
        {
            if(!currNode->left)
            {
                currNode->left=new Node(key);
                return;
            }
            currNode=currNode->left;
        }
        else{
            if(!currNode->right)
            {
                currNode->right=new Node(key);
                return;
            }
            currNode=currNode->right;
        }
    }
}
void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
Node *justSmallerNode(Node *root)
{
    root=root->left;
    while(root->right!=NULL) root=root->right;
    return root;
}
Node *deleteNode(Node *root,int key)
{
    if(root==NULL) return NULL;
    if(root->val > key)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(root->val < key)
    {
        root->right=deleteNode(root->right,key);
    }
    else{
        // currently at the Node to be deleted
        if(root->left==NULL && root->right==NULL) { //leaf Node
            free(root);
            return NULL;
        }  
        else if(!root->left) 
        {
            Node *temp=root->right;
            free(root);
            return temp;    // Node with right child only
        }
        else if(!root->right) {
            Node *temp=root->left;
            free(root);
            return temp;    // Node with right child only
        }
        else{
            //Node with 2 children
            Node *newNode=justSmallerNode(root);
            root->val=newNode->val;
            root->left=deleteNode(root->left,newNode->val);
        }
    }
    
    return root;
}
int main()
{
    BST bst;
    insert(bst.root,10);
    insert(bst.root,5);
    insert(bst.root,12);
    insert(bst.root,2);
    insert(bst.root,8);
    insert(bst.root,7);
    insert(bst.root,20);
    insert(bst.root,15);
    inorder(bst.root);
    cout<<endl;
    int t;
    cout<<"Enter chances: ";
    cin>>t;
    while(t--)
    {
        int key;
        cout<<"Enter key to be deleted: ";
        cin>>key;
        bst.root=deleteNode(bst.root,key);
        inorder(bst.root);
        cout<<endl;
    }
    return 0;
}