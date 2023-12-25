// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along
// the longest path from the root node down to the farthest leaf node.

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
int maxDepth(Node *root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;

    int leftSubTreeDepth=maxDepth(root->left);
    int rightSubTreeDepth=maxDepth(root->right);

    return max(leftSubTreeDepth,rightSubTreeDepth)+1;
}
int main()
{
    Node *root=new Node(2);                                   //     2
    root->left=new Node(4);                                   //   4   10
    root->right=new Node(10);                                 //  6 5     11
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    int maximumDepthOfGivenTree= maxDepth(root);
    cout<<"Maximum Depth: "<<maximumDepthOfGivenTree<<endl;
    return 0;
}