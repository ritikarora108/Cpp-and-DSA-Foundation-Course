// Pass Node by refernce while insertion

// Time Complexity for Insertion In BST:  
//       Average Case: O(log2n)
//       Worst Case:   O(n)  : if tree is skewed in one direction
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
void insertIteratively(Node *&root,int key)
{
    if(root==NULL) 
    {
        root=new Node(key);
        return;
    }
    Node *currNode=root;
    while(true)
    {
        if(currNode->val>key) 
        {
            if(!currNode->left) {
                currNode->left=new Node(key);
                return;
            }
            currNode=currNode->left;
        }
        else{
            if(!currNode->right) {
                currNode->right=new Node(key);
                return;
            }
            currNode=currNode->right; 
        }
    }
    return ;
}
void insertRecursively(Node *&root,int key)
{
    if(root==NULL)
    {
        root=new Node(key);
        return;
    }
    if(root->val > key)
    {
        insertRecursively(root->left,key);
        return ;
    } 
    insertRecursively(root->right,key);
}
void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    BST bst1;
    insertIteratively(bst1.root,8);
    insertIteratively(bst1.root,4);
    insertIteratively(bst1.root,5);
    insertIteratively(bst1.root,7);
   
    insertIteratively(bst1.root,12);
    insertIteratively(bst1.root,11);
    inorder(bst1.root);

    cout<<endl;

    BST bst2;
    insertRecursively(bst2.root,17);
    insertRecursively(bst2.root,22);
    insertRecursively(bst2.root,13);
    insertRecursively(bst2.root,40);
   
    insertRecursively(bst2.root,15);
    insertRecursively(bst2.root,6);
    inorder(bst2.root);

    cout<<endl;
}

