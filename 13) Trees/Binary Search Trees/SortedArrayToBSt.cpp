// Time Complexity:   O(n)
// Space Complexity:  O(logn)

#include<iostream>
#include<vector>
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
void preorder(Node *root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
Node *sortedArrayToBST(vector<int> &nums,int i,int j)
{
    int mid=(i+j)/2;
    Node *root=new Node(nums[mid]);
    if(i==j) return root;
    else if(i>j) return NULL;
    
    root->left=sortedArrayToBST(nums,i,mid-1);
    root->right=sortedArrayToBST(nums,mid+1,j);
    return root;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    BST bst;
    bst.root=sortedArrayToBST(arr,0,n-1);
    preorder(bst.root);
    cout<<endl;
    inorder(bst.root);
    return 0;
}

