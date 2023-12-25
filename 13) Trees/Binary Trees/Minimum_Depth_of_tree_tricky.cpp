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
int minDepth(Node *root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    if(root->left==NULL) return minDepth(root->right)+1;
    if(root->right==NULL) return minDepth(root->left)+1;

    return min(minDepth(root->left),minDepth(root->right))+1;
}
int main()
{
    Node *root=new Node(2);                                   //     2
    root->left=new Node(4);                                   //   4   10
    root->right=new Node(10);                                 //  6 5     11
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    int minimumDepthOfTree = minDepth(root);
    cout<<"Minimum depth: "<<minimumDepthOfTree<<endl;
    return 0;
}