// Time Complexity for Search operation In BST:  
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
bool searchIteratively(Node *root,int key)
{
    while(root!=NULL)
    {
        if(root->val==key) return true;
        else if(root->val > key) root=root->left;
        else root=root->right;
    }
    return false;
}
bool searchRecursively(Node *root,int key)
{
    if(root==NULL) return false;
    if(root->val==key) return true;
    else if(root->val > key) return searchRecursively(root->left,key);
    return searchRecursively(root->right,key);
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
    

    int key;
    cout<<"enter key:";
    cin>>key;
    if(searchIteratively(bst1.root,key)) cout<<key<<" is present (Iterative Search)"<<endl;
    else cout<<key<<" is not present (Iterative Search)"<<endl;

    if(searchRecursively(bst1.root,key)) cout<<key<<" is present (Recursive Search)"<<endl;
    else cout<<key<<" is not present (Recursive Search)"<<endl;
    
}
 